#pragma once

#include <iomanip>
#include <iostream>
#include <unistd.h>

class View {
public:
    View() = default;
    void clear();
    void change_gear();
    void check_oil();
    void display_engine_info(uint16_t, uint16_t, float, float, uint16_t, float, float, float, float, float, bool = false);
    void check_broken();
};
