#pragma once
#define CAPACITY 10
#include <string>
namespace vehicle {
	enum VehicleType {
		RAILWAY,
		WATER,
		AIR
	};
	enum EngineType {
		TURB,
		REACT
	};
	class Vehicle {
	private:
		VehicleType _model;
		std::string _name;
		float _k;
		float _a;
		EngineType _engine;
	public:
		VehicleType get_model();
		std::string get_name();
		float get_k();
		float get_a();
		EngineType get_engine();
		Vehicle(VehicleType type, std::string name, float k);
		Vehicle(VehicleType type, std::string name, float k, float a);
		Vehicle(VehicleType type, std::string name, float k, EngineType engine);
		Vehicle();
		float calc(float m, float d);
	};
	class VehicleList {
	private:
		Vehicle _vehicles[CAPACITY];
		int _size;
	public:
		VehicleList();
		int size();
		Vehicle operator[](int index);
		void insert(Vehicle vehicle, int index);
		void add(Vehicle vehicle);
		void remove(int index);
	};
	int min(VehicleList& vehicles, float m, float d);
}