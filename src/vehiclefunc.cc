#include <functions/vehiclearg.h>
#include <cmath>
#include <string>

using namespace std;
using namespace vehicle;
Vehicle::Vehicle() : _name(""), _k(0) {}
Vehicle::Vehicle(const std::string& name, double k) : _name(name), _k(k) {}
string Vehicle::get_name() const { return _name; }
double Vehicle::get_k() const { return _k; }

Railway::Railway() : Vehicle() {}
Railway::Railway(const std::string& name, double k) : Vehicle(name, k) {}
void Railway::print() const { cout << "Тип транспорта: Железнодорожный\n   Модель: " << _name << "\n   Базовый тариф перевозки: " << _k << "р." << endl; }
shared_ptr<Vehicle> Railway::clone() const { return make_shared<Railway>(_name, _k); }
double Railway::calc(double m, double d) { return _k*m*d; }

Water::Water() : Vehicle(), _a(0) {}
Water::Water(const std::string& name, double k, double a) : Vehicle(name, k), _a(a) {}
double Water::get_a() const { return _a; }
void Water::print() const { cout << "Тип транспорта: Водный\n   Модель: " << _name << "\n   Базовый тариф перевозки: " << _k << "р." << endl; }
shared_ptr<Vehicle> Water::clone() const { return make_shared<Water>(_name, _k, _a); }
double Water::calc(double m,double d) { return _k*m*d*pow(_a,d/5000); }

Air::Air() : Vehicle(), _engine(REACT) {}
Air::Air(const std::string& name, double k, EngineType engine) : Vehicle(name, k), _engine(engine) {}
std::string Air::get_engine() const {
    switch (_engine)
    {
    case EngineType::TURB:
        return "Turboprop";
    case EngineType::REACT:
        return "Reactive";
    default:
        throw runtime_error("Unknown type");
    }
}
void Air::print() const { cout << "Тип транспорта: Воздушный\n   Модель: " << _name << "\n   Базовый тариф перевозки: " << _k << "р." << endl; }
shared_ptr<Vehicle> Air::clone() const { return make_shared<Air>(_name, _k, _engine); }
double Air::calc(double m, double d) {
    if (get_engine() == "Turboprop") {
        if (d < 1000) return _k * m * d * 0.5;
        else return _k * m * d * 1.5;
    }
    else if (get_engine() == "Reactive") {
        if (d < 1000) return _k * m * d * 1.5;
        else return _k * m * d * 0.5;
    }
}
