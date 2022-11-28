#include "strut.h"

Strut::Strut()
        : stifness(0)
        , damping_rate(0) {}
Strut::Strut(const Strut& copy)
        : stifness(copy.stifness)
        , damping_rate(copy.damping_rate) {}
Strut::Strut(uint32_t stifness, uint16_t damping_rate)
        : stifness(stifness)
        , damping_rate(damping_rate) {}

void Strut::set_stifness(uint32_t s) {
    stifness = s;
}

void Strut::set_damping_rate(uint16_t h) {
    damping_rate = h;
}

uint32_t Strut::get_stifness() {
    return stifness;
}

uint16_t Strut::get_damping_rate() {
    return damping_rate;
}