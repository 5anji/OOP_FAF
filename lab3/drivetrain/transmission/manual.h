#pragma once

#include "components/clutch.h"
#include "components/gear_ratios.h"

class Manual {
    Clutch coupler_type;
    Gear_Ratios ratios;

public:
    Manual()
            : coupler_type(Clutch())
            , ratios(Gear_Ratios()) {}

    Manual(const Clutch& coupler_type, const Gear_Ratios& ratios)
            : coupler_type(coupler_type)
            , ratios(ratios) {}

    void set_coupler(const Clutch& data) {
        coupler_type.set_torque(const_cast<Clutch&>(data).get_torque());
        coupler_type.set_friction(const_cast<Clutch&>(data).get_friction());
    }

    void set_ratios(const Gear_Ratios& v) {
        ratios.set_g_count(const_cast<Gear_Ratios&>(v).get_g_count());
        ratios.set_ratios(const_cast<Gear_Ratios&>(v).get_ratios());
    }

    Clutch& get_coupler() { return coupler_type; }

    Gear_Ratios& get_ratios() { return ratios; }
};