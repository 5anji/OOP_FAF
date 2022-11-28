#pragma once
#include "../../damage.h"
#include "forced_induction.h"

#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>

class TurboCharger : public Forced_Induction
        , public Damage {
    std::map<int, float> psi_at_rpm;

public:
    TurboCharger();
    TurboCharger(const TurboCharger&);
    TurboCharger(std::map<int, float>);
    float get_pressure_PSI(uint16_t) final;
};