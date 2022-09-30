#pragma once

template <typename T>
struct Suspension {
    virtual void set_spring_t(const T&) = 0;
    virtual void set_is_powered(bool) = 0;
    virtual T get_spring_t() = 0;
    virtual bool get_is_powered() = 0;
};
