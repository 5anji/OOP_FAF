#pragma once

#include <cstdint>

class Torque_Converter {
    uint32_t max_torque;
    float friction_ratio;

public:
    Torque_Converter();

    Torque_Converter(const Torque_Converter&);

    Torque_Converter(uint32_t, float = 0.86f);

    void set_torque(uint32_t);

    void set_friction(float);

    uint32_t get_torque();
    float get_friction();
};