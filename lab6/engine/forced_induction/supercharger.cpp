#include "supercharger.h"

SuperCharger::SuperCharger(const SuperCharger& copy)
        : ratio(copy.ratio) {}

SuperCharger::SuperCharger(float ratio)
        : ratio(ratio) {}

float SuperCharger::get_pressure_PSI(uint16_t rpm) {
    return integrity * (3 + 0.6 * ratio * (static_cast<float>(rpm) / 1000.f));
}

float SuperCharger::get_ratio() { return ratio; }