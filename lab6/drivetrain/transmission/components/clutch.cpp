#include "clutch.h"

Clutch::Clutch()
        : max_torque(0)
        , friction_ratio(0.98f) {}

Clutch::Clutch(const Clutch& copy)
        : max_torque(copy.max_torque)
        , friction_ratio(copy.friction_ratio) {}

Clutch::Clutch(uint32_t max_torque, float friction_ratio)
        : max_torque(max_torque)
        , friction_ratio(friction_ratio) {}

void Clutch::set_torque(uint32_t data) { max_torque = data; }

void Clutch::set_friction(float ratio) { friction_ratio = ratio; }

uint32_t Clutch::get_torque() { return max_torque; }

float Clutch::get_friction() { return friction_ratio; }