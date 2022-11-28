#pragma once
#include "../../damage.h"

#include <cstdint>

class EngineHead {
    float compression;
    float max_torque;

public:
    EngineHead();

    EngineHead(const EngineHead&);

    EngineHead(float, float);

    float get_added_torque_ratio();

    float get_max_torque();
};