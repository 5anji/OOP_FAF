#pragma once

#include "../../damage.h"
#include "forced_induction.h"

#include <cstdint>

class SuperCharger : public Forced_Induction
        , public Damage {
    float ratio;

public:
    SuperCharger(const SuperCharger&);

    SuperCharger(float);

    float get_pressure_PSI(uint16_t) final;

    float get_ratio();
};