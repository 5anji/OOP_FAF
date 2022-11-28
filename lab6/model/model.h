#pragma once
#include "../drivetrain/differential.h"
#include "../drivetrain/transmission/manual.h"
#include "../engine/engine.h"
#include "../suspension/systems/dependent/live_axle.h"
#include "../wheels/rim.h"
#include "../wheels/tire.h"

class Model {
    Rim rim;
    Tire tire;
    LeafSpring leaf;
    Suspension<LeafSpring>* axle;
    Clutch coupler;
    Gearbox<Clutch>* gearbox;
    Forced_Induction* f_ind;
    EngineHead head;
    ShortBlock block;
    Differential diff;
    Engine<TurboCharger>* engine;

public:
    Model();
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
    ~Model();
};