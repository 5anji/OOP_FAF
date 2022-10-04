#pragma once

struct Damage {
    Damage()
            : integrity(1.f) {}
    Damage(float integrity)
            : integrity(integrity) {}
    void set_damage(float dmg) {
        integrity = dmg;
    }

protected:
    float integrity;
};