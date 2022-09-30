#pragma once

#include "forced induction/supercharger.h"
#include "forced induction/turbo.h"
#include "long block/engine_head.h"
#include "long block/short_block.h"

template <typename T>
class Engine {
    T forced_induction_type;
    EngineHead head;
    ShortBlock block;

public:
    Engine() = default;

    Engine(const Engine<T>& copy)
            : forced_induction_type(copy.forced_induction_type)
            , head(copy.head)
            , block(copy.block) {}

    Engine(T& forced_induction_type, EngineHead& head, ShortBlock& block)
            : forced_induction_type(forced_induction_type) {}

    float get_torque_at_rpm() {
        std::cout << "Invalid data type. Select supercharger or turbocharger" << std::endl;
    }
};