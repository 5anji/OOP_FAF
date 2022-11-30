#include "controller.h"

Controller::Controller(float scale)
        : RPM(800)
        , gear(2)
        , delta(0.9997f, 1.f)
        , oil_checker(false)
        , simulation_speed_scale(scale)
        , runs(1) {}

Controller::Controller(const Model& model, const View& view, float scale)
        : model(model)
        , view(view)
        , RPM(800)
        , gear(2)
        , delta(0.9997f, 1.f)
        , oil_checker(false)
        , simulation_speed_scale(scale)
        , runs(1) {
}

Rim& Controller::get_rim() { return model.get_rim(); }
void Controller::set_rim(Rim& copy) { model.set_rim(copy); }

Tire& Controller::get_tire() { return model.get_tire(); }
void Controller::set_tire(Tire& copy) { model.set_tire(copy); }

LeafSpring& Controller::get_leaf() { return model.get_leaf(); }
void Controller::set_leaf(LeafSpring& copy) { model.set_leaf(copy); }

Suspension<LeafSpring>* Controller::get_axle() { return model.get_axle(); }
void Controller::set_axle(Suspension<LeafSpring>* copy) { model.set_axle(copy); }

Clutch& Controller::get_coupler() { return model.get_coupler(); }
void Controller::set_coupler(Clutch& copy) { model.set_coupler(copy); }

Gearbox<Clutch>* Controller::get_gearbox() { return model.get_gearbox(); }
void Controller::set_gearbox(Gearbox<Clutch>* copy) { model.set_gearbox(copy); }

Forced_Induction* Controller::get_f_ind() { return model.get_f_ind(); }
void Controller::set_f_ind(Forced_Induction* copy) { model.set_f_ind(copy); }

EngineHead& Controller::get_head() { return model.get_head(); }
void Controller::set_head(EngineHead& copy) { model.set_head(copy); }

ShortBlock& Controller::get_block() { return model.get_block(); }
void Controller::set_block(ShortBlock& copy) { model.set_block(copy); }

Differential& Controller::get_diff() { return model.get_diff(); }
void Controller::set_diff(Differential& copy) { model.set_diff(copy); }

Engine<TurboCharger>* Controller::get_engine() { return model.get_engine(); }
void Controller::set_engine(Engine<TurboCharger>* copy) { model.set_engine(copy); }

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