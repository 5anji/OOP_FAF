
#include "torque_converter.h"

Torque_Converter::Torque_Converter()
        : max_torque(0)
        , friction_ratio(0.86f) {}

Torque_Converter::Torque_Converter(const Torque_Converter& copy)
        : max_torque(copy.max_torque)
        , friction_ratio(copy.friction_ratio) {}

Torque_Converter::Torque_Converter(uint32_t max_torque, float friction_ratio)
        : max_torque(max_torque)
        , friction_ratio(friction_ratio) {}

void Torque_Converter::set_torque(uint32_t data) { max_torque = data; }

void Torque_Converter::set_friction(float ratio) { friction_ratio = ratio; }

uint32_t Torque_Converter::get_torque() { return max_torque; }

float Torque_Converter::get_friction() { return friction_ratio; }