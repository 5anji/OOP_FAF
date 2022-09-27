#pragma once
#include <cstdint>

class EngineHead {
    float compression;
    float max_torque;

public:
    EngineHead()
            : compression(0.f)
            , max_torque(0.f) {}

    EngineHead(const EngineHead& copy)
            : compression(copy.compression)
            , max_torque(copy.max_torque) {}

    EngineHead(float compression, float max_torque)
            : compression(compression)
            , max_torque(max_torque) {}

    float get_added_torque_ratio() {
        return compression / 10.2f;
    }

    float get_max_torque() {
        return max_torque;
    }
};