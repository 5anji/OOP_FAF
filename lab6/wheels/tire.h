#pragma once
#include <cstdint>

class Tire {
    uint16_t width_mm, aspect_ratio;
    float diameter;

public:
    Tire();
    Tire(const Tire&);

    Tire(uint16_t, uint16_t, float);

    void set_tire_data(uint16_t, uint16_t, float);

    uint16_t get_width();

    uint16_t get_aspect_ratio();

    float get_diameter();
};
