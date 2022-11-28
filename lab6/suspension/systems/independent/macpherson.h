#pragma once
#include "../../springs/strut.h"
#include "../suspension.h"

#include <cstdint>

class MacPherson {
    Strut spring_t;
    bool is_powered;

public:
    MacPherson()
            : spring_t(0)
            , is_powered(0) {}
    MacPherson(const MacPherson& copy)
            : spring_t(copy.spring_t)
            , is_powered(copy.is_powered) {}
    MacPherson(Strut& spring_t, bool is_powered = false)
            : spring_t(spring_t)
            , is_powered(is_powered) {}

    void set_spring_t(Strut& s) {
        spring_t = s;
    }

    void set_is_powered(bool h) {
        is_powered = h;
    }

    Strut get_spring_t() {
        return spring_t;
    }

    bool get_is_powered() {
        return is_powered;
    }
};