#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "Keeper.h"
#include "Order.h"

using namespace std;

Keeper major;

//void searchLoop();
void editMenu();
void removeMenu();

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (1) 
	{
		cout << "Меню: \n";
		cout << "1. Открыть структуру \n";
		cout << "2. Добавить структуру \n";
		cout << "3. Редактировать \n";
		cout << "4. Удалить \n";
		cout << "5. Сохранить в файл \n";
		cout << "6. Загрузить из файла \n";
		cout << "ESC. Выход \n\n";
		cout << "Выберите нужное действие: ";

		char command = _getch();
		system("@cls||clear");

		switch (command)
		{
		case '1':
			major.print();
			break;

		case '2':
			major.add(new Order());
			break;

		case '3':
			editMenu();
			break;

		case '4':
			removeMenu();
			break;

		case '5':
			major.save();
			break;

		case '6':
			major.load();
			break;

		case 27:
			exit(0);
		}
		system("@cls||clear");
	}
}

//void searchLoop() {
//	if (!check()) return;
//
//	int counter = 0;
//	int mounth;
//
//	cout << "Введите месяц: ";
//	cin >> mounth;
//	cin.get();
//
//	major.sort();
//	major.printHead();
//
//	for (size_t i = 0; i < major.getSize(); i++) {
//		int currentMounth = major.getList()[i]->getBithday()[1];
//		if (currentMounth == mounth) {
//			cout << major.getList()[i]->toString() << endl;
//			counter++;
//		}
//	}
//
//	if (!counter) {
//		system("@cls||clear");
//		cout << endl << "\033[31mНичего не найдено =(\033[0m" << endl;
//
//	}
//
//	cout << endl << "\033[35mНажмите любую клавишу чтобы вернутся в меню\033[0m" << endl;
//
//	cin.get();
//}

void editMenu() 
{
	if (major.isEmpty())
		return;

	while (1)
	{
		system("@cls||clear");

		for (int i = 0; i < major.getSize(); i++)
		{
			cout << "Номер: " << (i + 1) << "\n";
			major.getStructure()[i]->print();
			cout << "\n";
		}

		int num;

		cout << "\nВведите номер объекта: ";
		cin >> num;
		cin.ignore();

		if (num < 1 || num > major.getSize())
		{
			cout << "\nТакого объекта нет \n";
			cout << "\"nНажмите любую клавишу \n";
			_getch();
			continue;
		}

		system("@cls||clear");
		major.getStructure()[num - 1]->edit();
		return;
	}
}

void removeMenu() 
{
	if (major.isEmpty())
		return;

	while (1)
	{
		system("@cls||clear");

		for (int i = 0; i < major.getSize(); i++)
		{
			cout << "Номер: " << (i + 1) << "\n";
			major.getStructure()[i]->print();
			cout << "\n";
		}

		int num;
		cout << "\nВведите номер объекта: ";
		cin >> num;
		cin.ignore();

		if (num < 1 || num > major.getSize())
		{
			cout << "\nТакого объекта нет \n";
			cout << "\nНажмите любую клавишу \n";
			_getch();
			continue;
		}

		system("@cls||clear");
		major.remove(num - 1);
		return;
	}
}