#pragma once
#include "../model/model.h"
#include "../view/view.h"

#include <random>

class Controller {
    Model model;
    View view;

    std::random_device generator;
    size_t RPM;
    size_t gear;
    std::uniform_real_distribution<float> delta;
    bool oil_checker;
    float simulation_speed_scale;
    size_t runs;

public:
    Controller(float = 5);
    int run();
};