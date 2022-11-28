#pragma once

#include "forced_induction/supercharger.h"
#include "forced_induction/turbo.h"
#include "long_block/engine_head.h"
#include "long_block/short_block.h"

template <typename T>
class Engine {
    Forced_Induction* forced_induction_type;
    EngineHead head;
    ShortBlock block;

public:
    Engine() = default;

    Engine(const Engine<T>& copy)
            : forced_induction_type(copy.forced_induction_type)
            , head(copy.head)
            , block(copy.block) {}

    Engine(Forced_Induction* forced_induction_type, EngineHead& head, ShortBlock& block)
            : forced_induction_type(forced_induction_type)
            , head(head)
            , block(block) {}

    float get_torque_at_rpm(uint32_t current_rpm) {
        return block.get_torque_Nm(current_rpm) * head.get_added_torque_ratio()
               + block.get_torque_Nm(current_rpm) * (forced_induction_type->get_pressure_PSI(current_rpm) / 14.7 + 10.2f) / 10.2f;
    }

    ~Engine() {
        delete forced_induction_type;
    }
};