#include "short_block.h"

ShortBlock::ShortBlock() {
    std::cout << "Input max rpm: ";
    std::cin >> max_rpm;
    std::cout << "Input idle rpm: ";
    std::cin >> idle_rpm;
    for (size_t i = idle_rpm; i <= max_rpm; i += 500) {
        size_t temp;
        std::cout << "Input torque(Nm) for " << i << " rpm: ";
        std::cin >> temp;
        torque_at_rpm[i] = temp;
    }
}

ShortBlock::ShortBlock(const ShortBlock& copy)
        : Damage()
        , torque_at_rpm(copy.torque_at_rpm)
        , max_rpm(copy.max_rpm)
        , idle_rpm(copy.idle_rpm) {}

ShortBlock::ShortBlock(std::map<int, float> torque_at_rpm, uint32_t max_rpm, uint32_t idle_rpm)
        : torque_at_rpm(torque_at_rpm)
        , max_rpm(max_rpm)
        , idle_rpm(idle_rpm) {}

float ShortBlock::get_torque_Nm(uint16_t rpm) {
    if (torque_at_rpm.find(rpm) != torque_at_rpm.end()) return torque_at_rpm.at(rpm);
    if (rpm < torque_at_rpm.begin()->first) return torque_at_rpm.begin()->second;
    if (rpm > torque_at_rpm.rbegin()->first) return torque_at_rpm.rbegin()->second;

    auto lower = torque_at_rpm.lower_bound(rpm) == torque_at_rpm.begin() ? torque_at_rpm.begin() : --(torque_at_rpm.lower_bound(rpm));
    auto upper = torque_at_rpm.upper_bound(rpm);

    return integrity * lower->second + (upper->second - lower->second) * float(rpm - lower->first) / fabs(upper->first - lower->first);
}

void ShortBlock::set(const std::tuple<std::map<int, float>, uint32_t, uint32_t>& that) {
    torque_at_rpm = std::get<0>(that);
    max_rpm = std::get<1>(that);
    idle_rpm = std::get<2>(that);
}

std::tuple<std::map<int, float>, uint32_t, uint32_t> ShortBlock::get() { return std::tuple<std::map<int, float>, uint32_t, uint32_t>(torque_at_rpm, max_rpm, idle_rpm); }