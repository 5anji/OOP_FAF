#pragma once

#include <algorithm>
#include <cstdint>
#include <vector>

class Gear_Ratios {
    uint8_t gears_count;
    std::vector<float> ratios;

public:
    Gear_Ratios();

    Gear_Ratios(uint8_t, const std::vector<float>&);

    void set_g_count(uint8_t);

    void set_ratios(const std::vector<float>&);

    uint8_t get_g_count();

    const std::vector<float>& get_ratios();
};