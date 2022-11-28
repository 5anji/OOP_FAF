#include "controller.h"

Controller::Controller(float scale)
        : RPM(800)
        , gear(2)
        , delta(0.9997f, 1.f)
        , oil_checker(false)
        , simulation_speed_scale(scale)
        , runs(1) {}

int Controller::run() {
    view.clear();

    do {
        if (RPM > 7000) {
            RPM = 800;
            view.change_gear();
            usleep(75E+5 / simulation_speed_scale);
            gear++;

            if (gear > 7) {
                runs++;
                gear = 2;
            }
        }
        usleep(6E+4 / simulation_speed_scale);
        view.clear();
        if (oil_checker) {
            view.check_oil();
        }

        float e_torque = model.get_engine()->get_torque_at_rpm(RPM);
        float w_torque = e_torque * model.get_gearbox()->get_coupler().get_friction() * model.get_gearbox()->get_ratios().get_ratios()[gear] * model.get_diff().get_gear_ratio();
        float w_speed = RPM * model.get_gearbox()->get_coupler().get_friction()
                        * (1 / model.get_gearbox()->get_ratios().get_ratios()[gear])
                        * (1 / model.get_diff().get_gear_ratio())
                        * (3.f / 25.f * M_PI * static_cast<float>(static_cast<float>(model.get_tire().get_width()) * static_cast<float>(model.get_tire().get_aspect_ratio()) / 100.f + static_cast<float>(model.get_rim().get_diameter()) * 25.4f) / 1000.f);
        view.display_engine_info(runs, gear - 1, model.get_gearbox()->get_ratios().get_ratios()[gear], model.get_diff().get_gear_ratio(), RPM, e_torque, w_torque, w_speed, model.get_block().get_damage(), dynamic_cast<TurboCharger*>(model.get_f_ind())->get_damage());
        RPM += 100;
        dynamic_cast<TurboCharger*>(model.get_f_ind())->set_damage(dynamic_cast<TurboCharger*>(model.get_f_ind())->get_damage() * delta(generator));
        model.get_block().set_damage(model.get_block().get_damage() * delta(generator));

        if (oil_checker) {
            dynamic_cast<TurboCharger*>(model.get_f_ind())->set_damage(dynamic_cast<TurboCharger*>(model.get_f_ind())->get_damage() * delta(generator) * delta(generator) * delta(generator));
            model.get_block().set_damage(model.get_block().get_damage() * delta(generator) * delta(generator));
        }
        model.set_engine(new Engine<TurboCharger>(model.get_f_ind(), model.get_head(), model.get_block()));
        if (dynamic_cast<TurboCharger*>(model.get_f_ind())->get_damage() < 0.5 || model.get_block().get_damage() < 0.7) {
            oil_checker = true;
            if (dynamic_cast<TurboCharger*>(model.get_f_ind())->get_damage() < 0.1 || model.get_block().get_damage() < 0.3) {
                view.check_broken();
                return 0;
            }
        }
    } while (true);
    return 0;
}