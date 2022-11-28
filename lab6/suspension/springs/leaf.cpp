#include "leaf.h"

LeafSpring::LeafSpring()
        : stifness(0)
        , height(0) {}
LeafSpring::LeafSpring(const LeafSpring& copy)
        : stifness(copy.stifness)
        , height(copy.height) {}
LeafSpring::LeafSpring(uint32_t stifness, uint32_t height)
        : stifness(stifness)
        , height(height) {}

void LeafSpring::set_stifness(uint32_t s) {
    stifness = s;
}

void LeafSpring::set_height(uint32_t h) {
    height = h;
}

uint32_t LeafSpring::get_stifness() {
    return stifness;
}

uint32_t LeafSpring::get_height() {
    return height;
}