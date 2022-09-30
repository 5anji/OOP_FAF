#pragma once

class Gear_Ratios;

template <typename T>
struct Gearbox {
    virtual void set_coupler(const T&) = 0;
    virtual void set_ratios(const Gear_Ratios&) = 0;
    virtual T get_coupler() = 0;
    virtual Gear_Ratios& get_ratios() = 0;
};
