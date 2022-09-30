#pragma once
#include <cstdint>

class SuperCharger {
    float ratio;

public:
    SuperCharger(const SuperCharger& copy)
            : ratio(copy.ratio) {}

    SuperCharger(float ratio)
            : ratio(ratio) {}

    float get_pressure_PSI(uint16_t rpm) {
        return 3 + 0.6 * ratio * (static_cast<float>(rpm) / 1000.f);
    }

    float get_ratio() { return ratio; }
};