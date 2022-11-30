#pragma once

template <typename T>
struct Suspension {
    virtual void set_spring_t(const T&) = 0;
    virtual void set_is_powered(bool) = 0;
    virtual T get_spring_t() = 0;
    virtual bool get_is_powered() = 0;
    virtual ~Suspension() = default;

protected:
    T spring_t;
    Suspension()
            : spring_t(T()) {
    }
    Suspension(const T& copy) : spring_t(copy) {}
};
