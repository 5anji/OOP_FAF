#pragma once
#include <cstdint>

class LeafSpring {
    uint32_t stifness;
    uint32_t height;

public:
    LeafSpring()
            : stifness(0)
            , height(0) {}
    LeafSpring(const LeafSpring& copy)
            : stifness(copy.stifness)
            , height(copy.height) {}
    LeafSpring(uint32_t stifness, uint32_t height = 0)
            : stifness(stifness)
            , height(height) {}

    void set_stifness(uint32_t s) {
        stifness = s;
    }

    void set_height(uint32_t h) {
        height = h;
    }

    uint32_t get_stifness() {
        return stifness;
    }

    uint32_t get_height() {
        return height;
    }
};