#pragma once

struct Damage {
protected:
    float integrity;

public:
    Damage()
            : integrity(1.f) {}
    Damage(float integrity)
            : integrity(integrity) {}
    void set_damage(float dmg) {
        integrity = dmg;
    }
    float get_damage() {
        return integrity;
    }
};