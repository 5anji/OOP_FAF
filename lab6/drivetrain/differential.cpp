#include "differential.h"

Differential::Differential()
        : gear_ratio(0.f)
        , lock_ratio(0.f) {}
Differential::Differential(const Differential& copy)
        : gear_ratio(copy.gear_ratio)
        , lock_ratio(copy.gear_ratio) {}
Differential::Differential(float gear_ratio, float lock_ratio)
        : gear_ratio(gear_ratio)
        , lock_ratio(lock_ratio) {}

void Differential::set_gear_ratio(float ratio) { gear_ratio = ratio; }

void Differential::set_lock_ratio(float ratio) { lock_ratio = ratio; }

float Differential::get_gear_ratio() { return gear_ratio; }

float Differential::get_lock_ratio() { return lock_ratio; }