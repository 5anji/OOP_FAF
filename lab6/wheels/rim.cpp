#include "rim.h"

Rim::Rim()
        : diameter(0.f)
        , width(0.f)
        , ET(0) {}
Rim::Rim(const Rim& copy)
        : diameter(copy.diameter)
        , width(copy.width)
        , ET(copy.ET) {}

Rim::Rim(float diameter, float width, uint8_t ET)
        : diameter(diameter)
        , width(width)
        , ET(ET) {}

void Rim::set_rim_data(float d, float w, uint8_t et) {
    diameter = d;
    width = w;
    ET = et;
}

float Rim::get_diameter() { return diameter; }

float Rim::get_width() { return width; }

uint8_t Rim::get_ET() { return ET; }
