#include <functions/vehiclearg.h>
#include <cmath>
#include <string>
using namespace std;
using namespace vehicle;
Vehicle::Vehicle(VehicleType model, string name, float k) :_model(model), _name(name), _k(k) {}
Vehicle::Vehicle(VehicleType model, string name, float k, float a) :_model(model), _name(name), _k(k), _a(a) {}
Vehicle::Vehicle(VehicleType model, string name, float k, EngineType engine) :_model(model), _name(name), _k(k), _engine(engine) {}
Vehicle::Vehicle() :_model(RAILWAY), _name(""), _k(1), _a(1), _engine(TURB) {}
VehicleType Vehicle::get_model() { return _model; }
string Vehicle::get_name() { return _name; }
float Vehicle::get_k() { return _k; }
float Vehicle::get_a() { return _a; }
EngineType Vehicle::get_engine() { return _engine; }
float Vehicle::calc(float m, float d) {
    switch (_model) {
    case RAILWAY:
        return _k * m * d;
    case WATER:
        return _k * m * d * pow(_a, d / 5000);
    case AIR:
        switch (_engine) {
        case TURB:
            if (d < 1000) return _k * m * d * 0.5;
            else return _k * m * d * 1.5;
        case REACT:
            if (d < 1000) return _k * m * d * 1.5;
            else return _k * m * d * 0.5;
        }
    }
}
int vehicle::min(VehicleList& vehicles, float m, float d) {
    int s = vehicles.size();
    int index = 0;
    float min_price = vehicles[0].calc(m,d);
    for (int i = 1; i < s; i++) {
        const float price = vehicles[i].calc(m, d);
        if (price < min_price) {
            index = i;
            min_price = price;
        }
    }
    return index;
}
