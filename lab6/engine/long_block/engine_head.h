#pragma once
#include "../../damage.h"

#include <cstdint>
#include <utility>

class EngineHead {
    float compression;
    float max_torque;

public:
    EngineHead();

    EngineHead(const EngineHead&);

    EngineHead(float, float);

    float get_added_torque_ratio();

    float get_max_torque();

    void set(const std::pair<float, float>&);

    std::pair<float, float> get();
};