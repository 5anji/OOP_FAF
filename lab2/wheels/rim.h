#pragma once
#include <cstdint>

class Rim {
    float diameter, width;
    uint8_t ET;

public:
    Rim()
            : diameter(0.f)
            , width(0.f)
            , ET(0) {}
    Rim(const Rim& copy)
            : diameter(copy.diameter)
            , width(copy.width)
            , ET(copy.ET) {}

    void set_rim_data(float d, float w, uint8_t et) {
        diameter = d;
        width = w;
        ET = et;
    }

    float get_diameter() { return diameter; }

    float get_width() { return width; }

    uint8_t get_ET() { return ET; }
};
