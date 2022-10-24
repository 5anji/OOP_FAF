#pragma once
#include <cstdint>

class Tire {
    uint16_t width_mm, aspect_ratio;
    float diameter;

public:
    Tire()
            : width_mm(0)
            , aspect_ratio(0)
            , diameter(0.f) {}
    Tire(const Tire& copy)
            : width_mm(copy.width_mm)
            , aspect_ratio(copy.aspect_ratio)
            , diameter(copy.diameter) {}

    Tire(uint16_t width, uint16_t ratio, float diameter)
            : width_mm(width)
            , aspect_ratio(ratio)
            , diameter(diameter) {}

    void set_tire_data(uint16_t width, uint16_t ratio, float diameter) {
        width_mm = width;
        aspect_ratio = ratio;
        this->diameter = diameter;
    }

    uint16_t get_width() { return width_mm; }

    uint16_t get_aspect_ratio() { return aspect_ratio; }

    float get_diameter() { return diameter; }
};
