#pragma once
#include <cstdint>

struct Forced_Induction {
    virtual float get_pressure_PSI(uint16_t) = 0;
    virtual ~Forced_Induction() = default;
};
