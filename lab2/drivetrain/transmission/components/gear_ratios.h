#include <algorithm>
#include <cstdint>
#include <vector>

class Gear_Ratios {
    uint8_t gears_count;
    std::vector<float> ratios;

public:
    Gear_Ratios()
            : gears_count(0)
            , ratios(std::vector<float>()) {}

    Gear_Ratios(uint8_t gears_count, const std::vector<float>& ratios)
            : gears_count(gears_count)
            , ratios(ratios) {
        std::sort(this->ratios.begin(), this->ratios.end());
    }

    void set_torque(uint8_t count) {
        gears_count = count;
    }

    void set_ratios(const std::vector<float>& v) {
        ratios = v;
        std::sort(this->ratios.begin(), this->ratios.end());
    }

    uint8_t get_torque() {
        return gears_count;
    }

    const std::vector<float>& get_ratios() {
        return ratios;
    }
};