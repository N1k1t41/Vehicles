#include <functions/vehiclearg.h>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace vehicle;
using namespace std;
void app(){
	cout << " ____________________________________________________________________" << endl;
	cout << " |                                ћеню                               |" << endl;
	cout << " Ч-------------------------------------------------------------------" << endl;
	cout << " | 1 - добавить транспорт											  |" << endl;
	cout << " | 2 - вставить транспорт по индексу                                 |" << endl;
	cout << " | 3 - удалить транспорт по индексу                                  |" << endl;
	cout << " | 4 - вывести список транспорта                                     |" << endl;
	cout << " | 5 - рассчитать стоимость перевозки                                |" << endl;
	cout << " | 6 - поиск первого траснпорта с наименьшей стоимостью перевозки    |" << endl;
	cout << " | 7 - выйти из системы                                              |" << endl;
	cout << "  -------------------------------------------------------------------" << endl;
}
shared_ptr<Vehicle> create_vehicle(){
	string name;
	int type;
	float k, a;
	int typeeng;
	cout << "¬ведите тип транспорта(Railway-1,Water-2,Air-3): ";
	cin >> type;
	if (type != 1 and type != 2 and type != 3)
		throw runtime_error("Unknown type");
	cout << "¬ведите название транспорта: ";
	getline(cin >> ws, name);
	cout << "¬ведите базовый тариф перевозки: ";
	cin >> k;
	switch (type)
	{
	case 1:
		return make_shared<Railway>(name, k);
	case 2:
		cout << "¬ведите поощр€ющий коэффицент: ";
		cin >> a;
		return make_shared<Water>(name, k, a);
	case 3:
		cout << "¬ведите тип двигател€: ";
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
			cout << "¬ведите индекс дл€ вставки транспорта: ";
			cin >> index;
			vehicles.insert(create_vehicle(), index);
			break;
		case 3:
			cout << "¬ведите индекс транспорта, который нужно удалить: ";
			cin >> index;
			vehicles.remove(index);
			break;
		case 4:
			vehicles.print();
			break;
		case 5:
			cout << "¬ведите массу товара: ";
			cin >> m;
			cout << "¬ведите рассто€ние: ";
			cin >> d;
			cout << "¬ведите индекс транспорта, стоимость перевозки которого нужно посчитать: ";
			cin >> index;
			cout << vehicles[index]->calc(m, d);
			break;
		case 6:
			cout << "¬ведите массу товара: ";
			cin >> m;
			cout << "¬ведите рассто€ние: ";
			cin >> d;
			cout << "»ндекс транспорта с минимальной стоимостью перевозки: " << vehicles.minim(m, d) << endl;
			break;
		}
	}
	return 0;
}
