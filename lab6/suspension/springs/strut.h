#pragma once
#include <cstdint>

class Strut {
    uint32_t stifness;
    uint16_t damping_rate;

public:
    Strut();
    Strut(const Strut&);
    Strut(uint32_t, uint16_t = 2);

    void set_stifness(uint32_t);

    void set_damping_rate(uint16_t);

    uint32_t get_stifness();

    uint16_t get_damping_rate();
};