#pragma once
#include "../../springs/leaf.h"
#include "../suspension.h"

#include <cstdint>

template <typename T = LeafSpring>
class Live_Axle : public Suspension<T> {
    bool is_powered;

public:
    Live_Axle()
            : Suspension<T>()
            , is_powered(0) {}
    Live_Axle(const Live_Axle& copy)
            : Suspension<T>(copy.spring_t)
            , is_powered(copy.is_powered) {}
    Live_Axle(LeafSpring& spring_t, bool is_powered = false)
            : Suspension<T>(spring_t)
            , is_powered(is_powered) {}

    void set_spring_t(const LeafSpring& s) override {
        Suspension<T>::spring_t = s;
    }

    void set_is_powered(bool h) override {
        is_powered = h;
    }

    LeafSpring get_spring_t() override {
        return Suspension<T>::spring_t;
    }

    bool get_is_powered() override {
        return is_powered;
    }
};