#pragma once

#include <cstdint>

class Clutch {
    uint32_t max_torque;
    float friction_ratio;

public:
    Clutch();

    Clutch(const Clutch&);
    Clutch(uint32_t, float = 0.98f);

    void set_torque(uint32_t);

    void set_friction(float ratio);

    uint32_t get_torque();

    float get_friction();
};