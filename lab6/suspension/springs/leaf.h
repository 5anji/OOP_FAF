#pragma once
#include <cstdint>

class LeafSpring {
    uint32_t stifness;
    uint32_t height;

public:
    LeafSpring();
    LeafSpring(const LeafSpring&);
    LeafSpring(uint32_t, uint32_t = 0);

    void set_stifness(uint32_t);

    void set_height(uint32_t);

    uint32_t get_stifness();

    uint32_t get_height();
};