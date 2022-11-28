#pragma once
#include <cstdint>

class Rim {
    float diameter, width;
    uint8_t ET;

public:
    Rim();
    Rim(const Rim&);

    Rim(float, float, uint8_t);

    void set_rim_data(float, float, uint8_t);

    float get_diameter();

    float get_width();

    uint8_t get_ET();
};
