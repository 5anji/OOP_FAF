#include "view.h"

void View::clear() { system("clear"); }

void View::change_gear() { std::cout << "Changing gear..." << std::flush; }

void View::check_oil() { std::cout << "Oil overheating!!!" << std::endl
                                   << std::endl
                                   << std::flush; }

void View::display_engine_info(uint8_t runs, uint8_t gear, float g_ratio, float d_ratio, uint16_t rpm, float e_torque, float w_torque, float w_speed, float b_damage, float i_damage) { std::cout << "Dyno test No: " << runs << std::endl
                  << "Gear: " << gear << std::endl
                  << "Gear ratio: " << g_ratio << std::endl
                  << "Diff ratio: " << d_ratio << std::endl
                  << "Current RPM: " << rpm << std::endl
                  << "Engine Torque: " << std::setprecision(2) << std::fixed << e_torque << " Nm" << std::endl
                  << "Wheel Torque: " << w_torque << " Nm" << std::endl
                  << "Wheel Speed: " << w_speed << " km/h" << std::endl
                  << "Damage: " << b_damage << ' ' << i_damage << std::endl
                  << std::endl
                  << std::flush;}
void View::check_broken() { std::cout << "Broken" << std::endl
                                      << std::flush; }