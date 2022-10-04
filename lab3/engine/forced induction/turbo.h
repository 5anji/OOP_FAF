#pragma once
#include "forced_induction.h"

#include <cstdint>
#include <iostream>
#include <map>

class TurboCharger : public Forced_Induction {
    std::map<int, float> psi_at_rpm;

public:
    TurboCharger() {
        size_t temp;
        std::cout << "Input max rpm: ";
        std::cin >> temp;
        for (size_t i = 500; i <= temp; i += 500) {
            size_t temp;
            std::cout << "Input psi for " << i << " rpm: ";
            std::cin >> temp;
            psi_at_rpm[i] = temp;
        }
    }

    TurboCharger(const TurboCharger& copy)
            : psi_at_rpm(copy.psi_at_rpm) {}

    TurboCharger(std::map<int, float> psi)
            : psi_at_rpm(psi) {}

    float get_pressure_PSI(uint16_t rpm) override {
        return psi_at_rpm[rpm];
    }
};