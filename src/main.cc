#include <functions/vehiclearg.h>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace vehicle;
using namespace std;
int main() {
	SetConsoleTitle("Vehicles");
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	int t;
	int f = 0;
	while (f == 0) {
		system("cls");
		cout << " ____________________________________________________________________" << endl;
		cout << " |                                ћеню                               |" << endl;
		cout << " Ч-------------------------------------------------------------------" << endl;
		cout << " | 1 - добавить транспорт                                            |" << endl;
		cout << " | 2 - добавить новый транспорт по индексу                           |" << endl;
		cout << " | 3 - удалить транспорт по индексу                                  |" << endl;
		cout << " | 4 - вывести список транспорта                                     |" << endl;
		cout << " | 5 - рассчитать цену транспортировки                               |" << endl;
		cout << " | 6 - поиск первого траснпорта с наименьшей ценой транспортировки   |" << endl;
		cout << " | 7 - выйти из системы                                              |" << endl;
		cout << "  -------------------------------------------------------------------" << endl;
		cin >> t;
		int s = 0;
		VehicleList vehicles;
		string type;
		switch (t) {
		case 1:
			while (s == 0) {
				cout << "¬ведите тип транспорта(Railway,Water,Air): ";
				cin >> type;
				if (type == "Railway") {
					VehicleType vtype = RAILWAY;
					string name;
					float k;
					cout << "¬ведите название траснпорта: ";
					cin >> name;
					cout << "¬ведите базовый тариф перевозки: ";
					cin >> k;
					auto v = Vehicle(vtype, name, k);
					vehicles.add(v);
					s++;
				}
				else if (type == "Water") {
					VehicleType vtype = WATER;
					string name;
					float a;
					float k;
					cout << "¬ведите название траснпорта: ";
					cin >> name;
					cout << "¬ведите базовый тариф перевозки: ";
					cin >> k;
					cout << "¬ведите поощр€ющий коэффицент: ";
					cin >> a;
					auto v = Vehicle(vtype, name, k, a);
					vehicles.add(v);
					s++;
				}
				else if (type == "Air") {
					VehicleType vtype = WATER;
					string name;
					string engine;
					EngineType eng;
					float k;
					cout << "¬ведите название траснпорта: ";
					cin >> name;
					cout << "¬ведите базовый тариф перевозки: ";
					cin >> k;
					int e = 0;
					while (e == 0) {
						cout << "¬ведите тип двигател€(Turboprop, Reactive)";
						cin >> engine;
						if (engine == "Turboprop") {
							eng = TURB;
							e++;
						}
						else if (engine == "Reactive") {
							eng = TURB;
							e++;
						}
						else  e = 0;
						auto v = Vehicle(vtype, name, k, eng);
						vehicles.add(v);
						s++;
					}
				}
				else {
					cout << "Ќеверный тип";
					s = 0;
				}
			}
			break;
		case 2:
			int index;
			cout << "¬ведите индекс: ";
			cin >> index;
			while (s == 0) {
				cout << "¬ведите тип транспорта(Railway,Water,Air): ";
				cin >> type;
				if (type == "Railway") {
					VehicleType vtype = RAILWAY;
					string name;
					float k;
					cout << "¬ведите название траснпорта: ";
					cin >> name;
					cout << "¬ведите базовый тариф перевозки: ";
					cin >> k;
					auto v = Vehicle(vtype, name, k);
					vehicles.insert(v, index);
					s++;
				}
				else if (type == "Water") {
					VehicleType vtype = WATER;
					string name;
					float a;
					float k;
					cout << "¬ведите название траснпорта: ";
					cin >> name;
					cout << "¬ведите базовый тариф перевозки: ";
					cin >> k;
					cout << "¬ведите поощр€ющий коэффицент: ";
					cin >> a;
					auto v = Vehicle(vtype, name, k, a);
					vehicles.insert(v, index);
					s++;
				}
				else if (type == "Air") {
					VehicleType vtype = WATER;
					string name;
					string engine;
					EngineType eng;
					float k;
					cout << "¬ведите название траснпорта: ";
					cin >> name;
					cout << "¬ведите базовый тариф перевозки: ";
					cin >> k;
					int e = 0;
					while (e == 0) {
						cout << "¬ведите тип двигател€(Turboprop, Reactive)";
						cin >> engine;
						if (engine == "Turboprop") {
							eng = TURB;
							e++;
						}
						else if (engine == "Reactive") {
							eng = TURB;
							e++;
						}
						else  e = 0;
						auto v = Vehicle(vtype, name, k, eng);
						vehicles.insert(v, index);
						s++;
					}
				}
				else {
					cout << "Ќеверный тип";
					s = 0;
				}
			}
			break;
		case 3:
			break;
		case 4:
			cout << vehicles;
			break;
		}
	}


}
