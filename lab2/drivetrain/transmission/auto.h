#pragma once

#include "components/gear_ratios.h"
#include "components/torque_converter.h"

class Auto {
    Torque_Converter coupler_type;
    Gear_Ratios ratios;

public:
    Auto()
            : coupler_type(Torque_Converter())
            , ratios(Gear_Ratios()) {}

    Auto(const Torque_Converter& coupler_type, const Gear_Ratios& ratios)
            : coupler_type(coupler_type)
            , ratios(ratios) {}

    void set_coupler(const Torque_Converter& data) {
        coupler_type.set_torque(const_cast<Torque_Converter&>(data).get_torque());
        coupler_type.set_friction(const_cast<Torque_Converter&>(data).get_friction());
    }

    void set_ratios(const Gear_Ratios& v) {
        ratios.set_g_count(const_cast<Gear_Ratios&>(v).get_g_count());
        ratios.set_ratios(const_cast<Gear_Ratios&>(v).get_ratios());
    }

    Torque_Converter& get_coupler() { return coupler_type; }

    Gear_Ratios& get_ratios() { return ratios; }
};