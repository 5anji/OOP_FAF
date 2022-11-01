#include "drivetrain/differential.h"
#include "drivetrain/transmission/manual.h"
#include "engine/engine.h"
#include "suspension/systems/dependent/live_axle.h"
#include "wheels/rim.h"
#include "wheels/tire.h"

#include <iomanip>
#include <iostream>
#include <random>
#include <unistd.h>

int main() {
    Rim rim(17, 8.5, 22);
    Tire tire;
    tire.set_tire_data(245, 35, 17);

    std::cout << tire.get_diameter() << std::endl;

    LeafSpring leaf(60000, 15);
    Suspension<LeafSpring>* axle = new Live_Axle(leaf, true);

    std::cout << axle->get_spring_t().get_stifness() << std::endl;

    Clutch coupler(500);
    Gearbox<Clutch>* gearbox = new Manual();
    gearbox->set_coupler(coupler);
    gearbox->set_ratios(Gear_Ratios(8, {-3.3, 0, 4.12, 3.7, 2.43, 1.72, 1.00, 0.89}));

    for (auto&& RPM : gearbox->get_ratios().get_ratios())
        std::cout << RPM << ' ';

    Forced_Induction* f_ind = new TurboCharger([] {
        std::map<int, float> turbo_map;
        turbo_map[1000] = 7;
        turbo_map[2000] = 13;
        turbo_map[3000] = 16;
        turbo_map[4000] = 18;
        turbo_map[5000] = 21;
        turbo_map[6000] = 20;
        turbo_map[7000] = 17;
        return turbo_map;
    }());

    EngineHead head(11.f, 700);
    ShortBlock block([] {
        std::map<int, float> tq_map;
        tq_map[1000] = 80;
        tq_map[2000] = 120;
        tq_map[3000] = 145;
        tq_map[4000] = 162;
        tq_map[5000] = 180;
        tq_map[6000] = 192;
        tq_map[7000] = 184;
        return tq_map;
    }(),
                     5000,
                     800);
    std::random_device generator;
    std::uniform_real_distribution<float> distributon(0.8f, 1.f);
    dynamic_cast<TurboCharger*>(f_ind)->set_damage(distributon(generator));

    std::cout << std::endl
              << "Using 6-th gear, for speed calculation:" << std::endl
              << std::endl;
    size_t RPM(800);
    size_t gear = 2;
    std::uniform_real_distribution<float> delta(0.92f, 1.f);

    Differential diff(3.45, 0.40);
    system("clear");
    Engine<TurboCharger>* engine = new Engine<TurboCharger>(f_ind, head, block);

    bool oil_checker(false);
    
    // set scale for simulation:
    int simulation_speed_scale = 10;

    do {
        float temp(delta(generator));
        if (RPM > 7000) {
            gear++;
            RPM = 800;
            std::cout << "Changing gear..." << std::flush;
            usleep(75E+4 / simulation_speed_scale);

            if (gear > 7) {
                gear = 2;
                dynamic_cast<TurboCharger*>(f_ind)->set_damage(dynamic_cast<TurboCharger*>(f_ind)->get_damage() * temp);
                block.set_damage(block.get_damage() * temp);
                
                if (oil_checker) {
                    dynamic_cast<TurboCharger*>(f_ind)->set_damage(dynamic_cast<TurboCharger*>(f_ind)->get_damage() * temp);
                    dynamic_cast<TurboCharger*>(f_ind)->set_damage(dynamic_cast<TurboCharger*>(f_ind)->get_damage() * temp);
                    block.set_damage(block.get_damage() * temp);
                    block.set_damage(block.get_damage() * temp);
                }
                engine = new Engine<TurboCharger>(f_ind, head, block);
                if (dynamic_cast<TurboCharger*>(f_ind)->get_damage() < 0.5 || block.get_damage() < 0.7) {
                    oil_checker = true;
                    if (dynamic_cast<TurboCharger*>(f_ind)->get_damage() < 0.1 || block.get_damage() < 0.3) {
                        std::cout << "\tBroken" << std::endl
                                  << std::flush;
                        goto cancel;
                    }
                }
            }
        }
        usleep(6E+4 / simulation_speed_scale);
        system("clear");
        if (oil_checker) {
            std::cout << "Oil overheating!!!" << std::endl
                      << std::endl
                      << std::flush;
        }

        float e_torque = engine->get_torque_at_rpm(RPM);
        float w_torque = e_torque * gearbox->get_coupler().get_friction() * gearbox->get_ratios().get_ratios()[gear] * diff.get_gear_ratio();
        float w_speed = RPM * gearbox->get_coupler().get_friction()
                        * (1 / gearbox->get_ratios().get_ratios()[gear])
                        * (1 / diff.get_gear_ratio())
                        * (3.f / 25.f * M_PI * static_cast<float>(static_cast<float>(tire.get_width()) * static_cast<float>(tire.get_aspect_ratio()) / 100.f + static_cast<float>(rim.get_diameter()) * 25.4f) / 1000.f);
        std::cout << "Gear: " << gear - 1 << std::endl
                  << "Gear ratio: " << gearbox->get_ratios().get_ratios()[gear] << std::endl
                  << "Diff ratio: " << diff.get_gear_ratio() << std::endl
                  << "Current RPM: " << RPM << std::endl
                  << "Engine Torque: " << std::setprecision(2) << std::fixed << e_torque << " Nm" << std::endl
                  << "Wheel Torque: " << w_torque << " Nm" << std::endl
                  << "Wheel Speed: " << w_speed << " km/h" << std::endl
                  << "Damage: " << block.get_damage() << ' ' << dynamic_cast<TurboCharger*>(f_ind)->get_damage() << std::endl
                  << std::endl
                  << std::flush;
        RPM += 100;
    } while (true);
cancel:
    delete engine;
    delete axle;
    delete gearbox;
    return 0;
}