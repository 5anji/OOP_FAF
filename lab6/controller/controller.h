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
    Controller(const Model&, const View&, float = 5);
    Rim& get_rim();
    void set_rim(Rim&);
    Tire& get_tire();
    void set_tire(Tire&);
    LeafSpring& get_leaf();
    void set_leaf(LeafSpring&);
    Suspension<LeafSpring>* get_axle();
    void set_axle(Suspension<LeafSpring>*);
    Clutch& get_coupler();
    void set_coupler(Clutch&);
    Gearbox<Clutch>* get_gearbox();
    void set_gearbox(Gearbox<Clutch>*);
    Forced_Induction* get_f_ind();
    void set_f_ind(Forced_Induction*);
    EngineHead& get_head();
    void set_head(EngineHead&);
    ShortBlock& get_block();
    void set_block(ShortBlock&);
    Differential& get_diff();
    void set_diff(Differential&);
    Engine<TurboCharger>* get_engine();
    void set_engine(Engine<TurboCharger>*);
    int run();
};