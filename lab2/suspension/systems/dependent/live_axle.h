#pragma once
#include "../../springs/leaf.h"

#include <cstdint>

class Live_Axle {
    LeafSpring spring_t;
    bool is_powered;

public:
    Live_Axle()
            : spring_t(0)
            , is_powered(0) {}
    Live_Axle(const Live_Axle& copy)
            : spring_t(copy.spring_t)
            , is_powered(copy.is_powered) {}
    Live_Axle(LeafSpring& spring_t, bool is_powered = false)
            : spring_t(spring_t)
            , is_powered(is_powered) {}

    void set_spring_t(LeafSpring& s) {
        spring_t = s;
    }

    void set_is_powered(bool h) {
        is_powered = h;
    }

    LeafSpring get_spring_t() {
        return spring_t;
    }

    bool get_is_powered() {
        return is_powered;
    }
};