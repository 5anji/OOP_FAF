#pragma once

#include <cstdint>

class Clutch {
    uint32_t max_torque;
    float friction_ratio;

public:
    Clutch()
            : max_torque(0)
            , friction_ratio(0.98f) {}

    Clutch(const Clutch& copy)
            : max_torque(copy.max_torque)
            , friction_ratio(copy.friction_ratio) {}

    Clutch(uint32_t max_torque, float friction_ratio = 0.98f)
            : max_torque(max_torque)
            , friction_ratio(friction_ratio) {}

    void set_torque(uint32_t data) { max_torque = data; }

    void set_friction(float ratio) { friction_ratio = ratio; }

    uint32_t get_torque() { return max_torque; }

    float get_friction() { return friction_ratio; }
};