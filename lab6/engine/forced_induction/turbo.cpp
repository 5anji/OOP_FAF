#include "turbo.h"

TurboCharger::TurboCharger() {
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

TurboCharger::TurboCharger(const TurboCharger& copy)
        : psi_at_rpm(copy.psi_at_rpm) {}

TurboCharger::TurboCharger(std::map<int, float> psi)
        : psi_at_rpm(psi) {}

float TurboCharger::get_pressure_PSI(uint16_t rpm) {
    if (psi_at_rpm.find(rpm) != psi_at_rpm.end()) return psi_at_rpm.at(rpm);
    if (rpm < psi_at_rpm.begin()->first) return psi_at_rpm.begin()->second;
    if (rpm > psi_at_rpm.rbegin()->first) return psi_at_rpm.rbegin()->second;

    auto lower = psi_at_rpm.lower_bound(rpm) == psi_at_rpm.begin() ? psi_at_rpm.begin() : --(psi_at_rpm.lower_bound(rpm));
    auto upper = psi_at_rpm.upper_bound(rpm);

    return integrity * lower->second + (upper->second - lower->second) * float(rpm - lower->first) / fabs(upper->first - lower->first);
}