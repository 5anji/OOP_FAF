#pragma once
#include <cstdint>

class Strut {
    uint32_t stifness;
    uint16_t damping_rate;

public:
    Strut()
            : stifness(0)
            , damping_rate(0) {}
    Strut(const Strut& copy)
            : stifness(copy.stifness)
            , damping_rate(copy.damping_rate) {}
    Strut(uint32_t stifness, uint16_t damping_rate = 2)
            : stifness(stifness)
            , damping_rate(damping_rate) {}

    void set_stifness(uint32_t s) {
        stifness = s;
    }

    void set_damping_rate(uint16_t h) {
        damping_rate = h;
    }

    uint32_t get_stifness() {
        return stifness;
    }

    uint16_t get_damping_rate() {
        return damping_rate;
    }
};