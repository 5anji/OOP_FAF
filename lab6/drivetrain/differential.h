#pragma once

class Differential {
    float gear_ratio;
    float lock_ratio;

public:
    Differential();
    Differential(const Differential&);
    Differential(float, float);
            
    void set_gear_ratio(float);

    void set_lock_ratio(float);

    float get_gear_ratio();

    float get_lock_ratio();
};