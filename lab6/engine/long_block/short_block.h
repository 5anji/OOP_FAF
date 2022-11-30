#pragma once
#include "../../damage.h"

#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>

class ShortBlock : public Damage {
    std::map<int, float> torque_at_rpm;
    uint32_t max_rpm;
    uint32_t idle_rpm;

public:
    ShortBlock();
    ShortBlock(const ShortBlock&);
    ShortBlock(std::map<int, float>, uint32_t, uint32_t);
    float get_torque_Nm(uint16_t);
    void set(const std::tuple<std::map<int, float>, uint32_t, uint32_t>&);
    std::tuple<std::map<int, float>, uint32_t, uint32_t> get();
};