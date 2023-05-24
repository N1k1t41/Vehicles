#include <functions/vehiclearg.h>
using namespace std;
using namespace vehicle;

VehicleList::VehicleList(const VehicleList& vehicles) {
	for (int i = 0; i < _vehicles.size(); ++i) {
		_vehicles.push_back(vehicles[i]->clone());
	}
};

VehicleList& VehicleList::operator=(VehicleList vehicles) {
	swap(vehicles);
	return *this;
}

void VehicleList::swap(VehicleList& vehicles) noexcept {
	_vehicles.swap(vehicles._vehicles);
}

void VehicleList::clear() {
	_vehicles.clear();
}

const VehiclePtr VehicleList::operator[](size_t index) const {
	if (index < 0 or _vehicles.size() <= index)
		throw out_of_range("Invalid index");
	return _vehicles[index];
}

VehiclePtr VehicleList::operator[](size_t index) {
	if (index < 0 or _vehicles.size() <= index)
		throw out_of_range("Invalid index");
	return _vehicles[index];
}

void VehicleList::add(VehiclePtr vehicle) {
	_vehicles.push_back(vehicle);
}

size_t VehicleList::get_size() const {
	return _vehicles.size();
}

void VehicleList::insert(VehiclePtr vehicle, int index) {
	if (index < 0 or _vehicles.size() <= index)
		throw runtime_error("[VehicleList::insert]Invalid index");

	_vehicles.insert(_vehicles.begin() + index, vehicle);
}

void VehicleList::remove(int index) {
	if (index < 0 or _vehicles.size() <= index)
		throw runtime_error("[VehicleList::remove]Invalid index");

	_vehicles.erase(_vehicles.begin() + index);
}

void VehicleList::print() const {
	for (int i = 0; i < _vehicles.size(); ++i) {
		cout << " " << i + 1 << ")";
		_vehicles[i]->print();
	}
	cout << endl;
}

int VehicleList::minim(double m, double d) {
	int s = _vehicles.size();
	int index = -1;
	double min_price = _vehicles[0]->calc(m, d);
	for (int i = 1; i < s; i++) {
		const double price = _vehicles[i]->calc(m, d);
		if ((index == -1) or (price < min_price)) {
			index = i;
			min_price = price;
		}
	}
	return index;
}