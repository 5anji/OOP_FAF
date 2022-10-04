#include "drivetrain/transmission/manual.h"
#include "engine/engine.h"
#include "suspension/systems/dependent/live_axle.h"
#include "wheels/rim.h"
#include "wheels/tire.h"

#include <iostream>
#include <random>

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

    for (auto&& i : gearbox->get_ratios().get_ratios())
        std::cout << i << ' ';

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
    std::uniform_real_distribution<float> distributon(0.9f, 1.f);
    block.set_damage(distributon(generator));
    Engine<TurboCharger> engine(f_ind, head, block);

    std::cout << std::endl;
    std::cout << engine.get_torque_at_rpm(4000) << std::endl;

    delete axle;
    delete gearbox;
    return 0;
}