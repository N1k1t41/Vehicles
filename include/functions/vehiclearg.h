#pragma once
#include <conio.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <windows.h>

namespace vehicle {
	enum EngineType {
		TURB,
		REACT
	};
	class Vehicle {
	protected:
		std::string _name;
		double _k;
	public:
		Vehicle();
		Vehicle(const std::string& name, double k);
		Vehicle(const Vehicle&) = default;
		Vehicle& operator=(const Vehicle&) = default;
		std::string get_name() const;
		double get_k() const;
		virtual double calc(double m, double d) = 0;
		virtual void print() const = 0;
		virtual std::shared_ptr<Vehicle> clone() const = 0;
	};

	class Railway : public Vehicle {
	public:
		Railway();
		Railway(const std::string& name, double k);
		double calc(double m, double d) override;
		std::shared_ptr<Vehicle> clone() const override;
		void print() const override;
	};

	class Water : public Vehicle {
	private:
		double _a;
	public:
		Water();
		Water(const std::string& name, double k, double a);
		double get_a() const;
		double calc(double m, double d) override;
		std::shared_ptr<Vehicle> clone() const override;
		void print() const override;
	};

	class Air : public Vehicle {
	private:
		EngineType _engine;
	public:
		Air();
		Air(const std::string& name, double k, EngineType engine);
		std::string get_engine() const;
		double calc(double m, double d) override;
		std::shared_ptr<Vehicle> clone() const override;
		void print() const override;
	};

	using VehiclePtr = std::shared_ptr<Vehicle>;

	class VehicleList{
	private:
		std::vector<VehiclePtr> _vehicles;
	public:
		VehicleList() = default;
		VehicleList(const VehicleList& list);
		VehicleList& operator=(VehicleList list);
		void swap(VehicleList& list) noexcept;
		const VehiclePtr operator[](size_t index) const;
		VehiclePtr operator[](size_t index);
		size_t get_size() const;
		void add(VehiclePtr vehicle);
		void insert(VehiclePtr vehicle, int index);
		void remove(int index);
		void print() const;
		void clear();
		int minim(double m, double d);
	};
}