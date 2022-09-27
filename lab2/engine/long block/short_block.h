#pragma once
#include <cstdint>
#include <iostream>
#include <map>

class ShortBlock {
    std::map<int, float> torque_at_rpm;
    uint32_t max_rpm;
    uint32_t idle_rpm;

public:
    ShortBlock() {
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

    ShortBlock(const ShortBlock& copy)
            : torque_at_rpm(copy.torque_at_rpm)
            , max_rpm(copy.max_rpm)
            , idle_rpm(copy.idle_rpm) {}

    ShortBlock(std::map<int, float> torque_at_rpm, uint32_t max_rpm, uint32_t idle_rpm)
            : torque_at_rpm(torque_at_rpm)
            , max_rpm(max_rpm)
            , idle_rpm(idle_rpm) {}

    float get_torque_Nm(uint16_t rpm) {
        return torque_at_rpm[rpm];
    }
};