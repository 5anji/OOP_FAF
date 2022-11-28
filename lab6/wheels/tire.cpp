#include "tire.h"

Tire::Tire()
        : width_mm(0)
        , aspect_ratio(0)
        , diameter(0.f) {}
Tire::Tire(const Tire& copy)
        : width_mm(copy.width_mm)
        , aspect_ratio(copy.aspect_ratio)
        , diameter(copy.diameter) {}

Tire::Tire(uint16_t width, uint16_t ratio, float diameter)
        : width_mm(width)
        , aspect_ratio(ratio)
        , diameter(diameter) {}

void Tire::set_tire_data(uint16_t width, uint16_t ratio, float diameter) {
    width_mm = width;
    aspect_ratio = ratio;
    this->diameter = diameter;
}

uint16_t Tire::get_width() { return width_mm; }

uint16_t Tire::get_aspect_ratio() { return aspect_ratio; }

float Tire::get_diameter() { return diameter; }
