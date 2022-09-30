#include "drivetrain/transmission/manual.h"
#include "suspension/systems/dependent/live_axle.h"
#include "wheels/rim.h"
#include "wheels/tire.h"

#include <iostream>

int main() {
    Rim rim(17, 8.5, 22);
    Tire tire;
    tire.set_tire_data(245, 35, 17);

    std::cout << tire.get_diameter() << std::endl;

    LeafSpring leaf(60000, 15);
    Live_Axle axle(leaf, true);

    std::cout << axle.get_spring_t().get_stifness() << std::endl;

    Clutch coupler(500);
    Gearbox<Clutch>* gearbox = new Manual();
    gearbox->set_coupler(coupler);
    gearbox->set_ratios(Gear_Ratios(8, {-3.3, 0, 4.12, 3.7, 2.43, 1.72, 1.00, 0.89}));

    for (auto&& i : gearbox->get_ratios().get_ratios()) {
        std::cout << i << ' ';
    }

    std::cout << std::endl;
    return 0;
}