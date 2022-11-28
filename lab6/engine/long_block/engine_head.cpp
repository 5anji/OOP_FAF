#include "engine_head.h"

EngineHead::EngineHead()
        : compression(0.f)
        , max_torque(0.f) {}

EngineHead::EngineHead(const EngineHead& copy)
        : compression(copy.compression)
        , max_torque(copy.max_torque) {}

EngineHead::EngineHead(float compression, float max_torque)
        : compression(compression)
        , max_torque(max_torque) {}

float EngineHead::get_added_torque_ratio() {
    return compression / 10.2f;
}

float EngineHead::get_max_torque() {
    return max_torque;
}