#include "model.h"

Model::Model()
        : rim(17, 8.5, 22)
        , tire(245, 35, 17)
        , leaf(60000, 15)
        , coupler(500)
        , head(11.f, 700)
        , block([] {
            std::map<int, float> tq_map;
            tq_map[1000] = 80;
            tq_map[2000] = 120;
            tq_map[3000] = 145;
            tq_map[4000] = 162;
            tq_map[5000] = 180;
            tq_map[6000] = 192;
            tq_map[7000] = 184;
            return tq_map;
        }(),
                5000,
                500)
        , diff(3.45, 0.40) {
    axle = new Live_Axle(leaf, true);
    gearbox = new Manual();
    gearbox->set_coupler(coupler);
    gearbox->set_ratios(Gear_Ratios(8, {-3.3, 0, 4.12, 3.7, 2.43, 1.72, 1.00, 0.89}));
    f_ind = new TurboCharger([] {
        std::map<int, float> turbo_map;
        turbo_map[1000] = 7;
        turbo_map[2000] = 13;
        turbo_map[3000] = 16;
        turbo_map[4000] = 18;
        turbo_map[5000] = 21;
        turbo_map[6000] = 20;
        turbo_map[7000] = 17;
        return turbo_map;
    }());
    engine = new Engine<TurboCharger>(f_ind, head, block);
}

Rim& Model::get_rim() { return rim; }
void Model::set_rim(Rim& copy) { rim.set_rim_data(copy.get_diameter(), copy.get_width(), copy.get_ET()); }

Tire& Model::get_tire() { return tire; }
void Model::set_tire(Tire& copy) { tire.set_tire_data(copy.get_width(), copy.get_aspect_ratio(), copy.get_aspect_ratio()); }

LeafSpring& Model::get_leaf() { return leaf; }
void Model::set_leaf(LeafSpring& copy) {
    leaf.set_height(copy.get_height());
    leaf.set_stifness(copy.get_stifness());
}

Suspension<LeafSpring>* Model::get_axle() { return axle; }
void Model::set_axle(Suspension<LeafSpring>* copy) { axle = copy; }

Clutch& Model::get_coupler() { return coupler; }
void Model::set_coupler(Clutch& copy) {
    coupler.set_friction(copy.get_friction());
    coupler.set_torque(copy.get_torque());
}

Gearbox<Clutch>* Model::get_gearbox() { return gearbox; }
void Model::set_gearbox(Gearbox<Clutch>* copy) { gearbox = copy; }

Forced_Induction* Model::get_f_ind() { return f_ind; }
void Model::set_f_ind(Forced_Induction* copy) { f_ind = copy; }

EngineHead& Model::get_head() { return head; }
void Model::set_head(EngineHead& copy) { head.set(copy.get()); }

ShortBlock& Model::get_block() { return block; }
void Model::set_block(ShortBlock& copy) { block.set(copy.get()); }

Differential& Model::get_diff() { return diff; }
void Model::set_diff(Differential& copy) {
    diff.set_gear_ratio(copy.get_gear_ratio());
    diff.set_lock_ratio(copy.get_lock_ratio());
}

Engine<TurboCharger>* Model::get_engine() { return engine; }
void Model::set_engine(Engine<TurboCharger>* copy) { engine = copy; }

Model::~Model() {
    delete engine;
    delete axle;
    delete gearbox;
}