#pragma once
#include <string>
#include <iostream>
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
		VehicleType _type;
		std::string _name;
		float _k;
		float _a;
		EngineType _engine;
	public:
		std::string get_type() const;
		std::string get_name() const;
		float get_k() const;
		float get_a() const;
		EngineType get_engine() const;
		Vehicle(VehicleType type, std::string name,float k);
		Vehicle(VehicleType type, std::string name, float k, float a);
		Vehicle(VehicleType type, std::string name, float k, EngineType engine);
		Vehicle();
		float calc(float m, float d);
	};
	std::ostream& operator<<(std::ostream& stream, const Vehicle& vehicle);
	class VehicleList {
	private:
		Vehicle** _vehicles;
		int _size;
	public:
		VehicleList(const VehicleList& copy);
		VehicleList();
		~VehicleList();
		int size() const ;
		const Vehicle& operator[](int index) const;
		Vehicle& operator[](int index);
		VehicleList& operator=(VehicleList copy);
		void swap(VehicleList& rhs) noexcept;
		void insert(Vehicle vehicle, int index);
		void add(Vehicle vehicle);
		void remove(int index);
		void clear();
		const Vehicle& get_vehicle(int index) const;
	};
	int min(VehicleList& vehicles, float m, float d);
	std::ostream& operator<<(std::ostream& stream, const VehicleList& vehicles);
}