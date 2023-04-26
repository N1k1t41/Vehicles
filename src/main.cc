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
		cout << " |                                ����                               |" << endl;
		cout << " �-------------------------------------------------------------------" << endl;
		cout << " | 1 - �������� ���������                                            |" << endl;
		cout << " | 2 - �������� ����� ��������� �� �������                           |" << endl;
		cout << " | 3 - ������� ��������� �� �������                                  |" << endl;
		cout << " | 4 - ������� ������ ����������                                     |" << endl;
		cout << " | 5 - ���������� ���� ���������������                               |" << endl;
		cout << " | 6 - ����� ������� ���������� � ���������� ����� ���������������   |" << endl;
		cout << " | 7 - ����� �� �������                                              |" << endl;
		cout << "  -------------------------------------------------------------------" << endl;
		cin >> t;
		int s = 0;
		VehicleList vehicles;
		string type;
		switch (t) {
		case 1:
			while (s == 0) {
				cout << "������� ��� ����������(Railway,Water,Air): ";
				cin >> type;
				if (type == "Railway") {
					VehicleType vtype = RAILWAY;
					string name;
					float k;
					cout << "������� �������� ����������: ";
					cin >> name;
					cout << "������� ������� ����� ���������: ";
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
					cout << "������� �������� ����������: ";
					cin >> name;
					cout << "������� ������� ����� ���������: ";
					cin >> k;
					cout << "������� ���������� ����������: ";
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
					cout << "������� �������� ����������: ";
					cin >> name;
					cout << "������� ������� ����� ���������: ";
					cin >> k;
					int e = 0;
					while (e == 0) {
						cout << "������� ��� ���������(Turboprop, Reactive)";
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
					cout << "�������� ���";
					s = 0;
				}
			}
			break;
		case 2:
			int index;
			cout << "������� ������: ";
			cin >> index;
			while (s == 0) {
				cout << "������� ��� ����������(Railway,Water,Air): ";
				cin >> type;
				if (type == "Railway") {
					VehicleType vtype = RAILWAY;
					string name;
					float k;
					cout << "������� �������� ����������: ";
					cin >> name;
					cout << "������� ������� ����� ���������: ";
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
					cout << "������� �������� ����������: ";
					cin >> name;
					cout << "������� ������� ����� ���������: ";
					cin >> k;
					cout << "������� ���������� ����������: ";
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
					cout << "������� �������� ����������: ";
					cin >> name;
					cout << "������� ������� ����� ���������: ";
					cin >> k;
					int e = 0;
					while (e == 0) {
						cout << "������� ��� ���������(Turboprop, Reactive)";
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
					cout << "�������� ���";
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
