#include <functions/vehiclearg.h>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace vehicle;
using namespace std;
void app(){
	cout << " ____________________________________________________________________" << endl;
	cout << " |                                ����                               |" << endl;
	cout << " �-------------------------------------------------------------------" << endl;
	cout << " | 1 - �������� ���������											  |" << endl;
	cout << " | 2 - �������� ��������� �� �������                                 |" << endl;
	cout << " | 3 - ������� ��������� �� �������                                  |" << endl;
	cout << " | 4 - ������� ������ ����������                                     |" << endl;
	cout << " | 5 - ���������� ��������� ���������                                |" << endl;
	cout << " | 6 - ����� ������� ���������� � ���������� ���������� ���������    |" << endl;
	cout << " | 7 - ����� �� �������                                              |" << endl;
	cout << "  -------------------------------------------------------------------" << endl;
}
shared_ptr<Vehicle> create_vehicle(){
	string name;
	int type;
	float k, a;
	int typeeng;
	cout << "������� ��� ����������(Railway-1,Water-2,Air-3): ";
	cin >> type;
	if (type != 1 and type != 2 and type != 3)
		throw runtime_error("Unknown type");
	cout << "������� �������� ����������: ";
	getline(cin >> ws, name);
	cout << "������� ������� ����� ���������: ";
	cin >> k;
	switch (type)
	{
	case 1:
		return make_shared<Railway>(name, k);
	case 2:
		cout << "������� ���������� ����������: ";
		cin >> a;
		return make_shared<Water>(name, k, a);
	case 3:
		cout << "������� ��� ���������: ";
		cin >> typeeng;
		return make_shared<Air>(name, k, (EngineType)typeeng);
	}
}
int main()
{
	SetConsoleTitle("Vehicles");
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	VehicleList vehicles;
	app();
	while (true)
	{
		int k;
		cin >> k;
		int index = 0;
		float m, d;
		system("cls");
		app();
		if (k == 7) {
			vehicles.clear();
			break;
		}
		switch (k)
		{
		case 1:
			system("cls");
			vehicles.add(create_vehicle());
			system("cls");
			app();
			break;
		case 2:
			cout << "������� ������ ��� ������� ����������: ";
			cin >> index;
			vehicles.insert(create_vehicle(), index);
			break;
		case 3:
			cout << "������� ������ ����������, ������� ����� �������: ";
			cin >> index;
			vehicles.remove(index);
			break;
		case 4:
			vehicles.print();
			break;
		case 5:
			cout << "������� ����� ������: ";
			cin >> m;
			cout << "������� ����������: ";
			cin >> d;
			cout << "������� ������ ����������, ��������� ��������� �������� ����� ���������: ";
			cin >> index;
			cout << vehicles[index]->calc(m, d);
			break;
		case 6:
			cout << "������� ����� ������: ";
			cin >> m;
			cout << "������� ����������: ";
			cin >> d;
			cout << "������ ���������� � ����������� ���������� ���������: " << vehicles.minim(m, d) << endl;
			break;
		}
	}
	return 0;
}
