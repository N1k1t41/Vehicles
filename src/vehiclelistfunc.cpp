#include <functions/vehiclearg.h>
#include <stdexcept>
using namespace vehicle;
using namespace std;
VehicleList::VehicleList() :_size(0) {}	
int VehicleList::size(){
	return _size;
}
Vehicle VehicleList::operator[](int index) {
	if (index < 0 or index >= _size) {
		throw out_of_range("error");
	}
	return _vehicles[index];
}
void VehicleList::insert(Vehicle vehicle, int index) {
	if (index < 0 or index >= CAPACITY) {
		throw runtime_error("error");
	}
	for (int i = _size - 1; i >= index; --i) {
		_vehicles[i] = _vehicles[i - 1];
	}
	_vehicles[index] = vehicle;
	_size++;
}
void VehicleList::add(Vehicle vehicle) {
	if (_size == CAPACITY) {
		throw runtime_error("error");
	}
	_vehicles[_size] = vehicle;
	_size++;
}
void VehicleList::remove(int index) {
	if (index < 0 or index >= _size) {
		throw runtime_error("error");
	}
	for (int i = index; i < _size - 1; i++) {
		_vehicles[i] = _vehicles[i + 1];
	}
	_size--;
}