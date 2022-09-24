#include <cstdint>

class Clutch {
    uint32_t max_torque;
    float friction;

public:
    Clutch()
            : max_torque(0)
            , friction(0.f) {}

    Clutch(uint32_t max_torque, float friction)
            : max_torque(max_torque)
            , friction(friction) {}

    void set_torque(uint32_t data) {
        max_torque = data;
    }

    void set_friction(float ratio) {
        friction = ratio;
    }

    uint32_t get_torque() {
        return max_torque;
    }

    float get_friction() {
        return friction;
    }
};