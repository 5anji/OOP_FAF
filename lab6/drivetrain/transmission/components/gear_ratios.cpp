#include "gear_ratios.h"

Gear_Ratios::Gear_Ratios()
        : gears_count(0)
        , ratios(std::vector<float>()) {}

Gear_Ratios::Gear_Ratios(uint8_t gears_count, const std::vector<float>& ratios)
        : gears_count(gears_count)
        , ratios(ratios) {
    std::sort(this->ratios.begin(), this->ratios.end(), [](float a, float b) {
        return (b <= 0) && (a < b);
    });
}

void Gear_Ratios::set_g_count(uint8_t count) { gears_count = count; }

void Gear_Ratios::set_ratios(const std::vector<float>& v) {
    ratios = v;
    std::sort(this->ratios.begin(), this->ratios.end(), [](float a, float b) {
        return (b <= 0) && (a < b);
    });
}

uint8_t Gear_Ratios::get_g_count() {
    return gears_count;
}

const std::vector<float>& Gear_Ratios::get_ratios() {
    return ratios;
}