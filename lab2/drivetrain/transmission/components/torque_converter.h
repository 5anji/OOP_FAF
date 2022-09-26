#include <cstdint>

class Torque_Converter {
    uint32_t max_torque;
    float friction_ratio;

public:
    Torque_Converter()
            : max_torque(0)
            , friction_ratio(0.86f) {}

    Torque_Converter(uint32_t max_torque, float friction_ratio = 0.86f)
            : max_torque(max_torque)
            , friction_ratio(friction_ratio) {}

    void set_torque(uint32_t data) {
        max_torque = data;
    }

    void set_friction(float ratio) {
        friction_ratio = ratio;
    }

    uint32_t get_torque() {
        return max_torque;
    }

    float get_friction() {
        return friction_ratio;
    }
};