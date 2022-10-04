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
        return tq_map;
    }(),
                     5000,
                     800);
    std::random_device generator;
    std::uniform_real_distribution<float> distributon(0.5f, 1.f);
    dynamic_cast<TurboCharger*>(f_ind)->set_damage(distributon(generator));
    Engine<TurboCharger> engine(f_ind, head, block);

    std::cout << std::endl
              << "Using 5-th gear, for speed calculation:" << std::endl
              << std::endl;
    size_t RPM(1000);

    std::uniform_real_distribution<float> delta(0.95f, 1.f);

    Differential diff(3.45, 0.40);

    while (true) {
        float temp(delta(generator));
        usleep(25E+4);

        if (RPM > 5000) {
            goto cancel;
        }
        float e_torque = temp * engine.get_torque_at_rpm(RPM);
        float w_torque = e_torque * gearbox->get_coupler().get_friction() * gearbox->get_ratios().get_ratios()[6] * diff.get_gear_ratio();
        float w_speed = temp * RPM * gearbox->get_coupler().get_friction()
                        * (1 / gearbox->get_ratios().get_ratios()[6])
                        * (1 / diff.get_gear_ratio())
                        * (3.f / 25.f * M_PI * static_cast<float>(static_cast<float>(tire.get_width()) * static_cast<float>(tire.get_aspect_ratio()) / 100.f + static_cast<float>(rim.get_diameter()) * 25.4f) / 1000.f);
        std::cout << "Current RPM: " << RPM << std::endl
                  << "Engine Torque: " << std::setprecision(2) << std::fixed << e_torque << "Nm" << std::endl
                  << "Wheel Torque: " << w_torque << std::endl
                  << "Wheel Speed: " << w_speed << "km/h" << std::endl
                  << std::endl
                  << std::flush;
        RPM += 1000;
    }
cancel:
    delete axle;
    delete gearbox;
    return 0;
}