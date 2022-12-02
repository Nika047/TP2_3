#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "Keeper.h"
#include "Order.h"

using namespace std;

Keeper major;

void menu();
void first();
int second();
void findMenu();
void editMenu();
void removeMenu();
void repeatMenu();

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
}

void menu()
{
	cout << "Выберите действие: \n";
	cout << "1. Проверка первого задания  \n";
	cout << "2. Проверка второго задания  \n";
	cout << "ESC. Выход  \n";
	cout << "\nВыберите номер команды: ";

	char command = _getch();
	system("@cls||clear");

	switch (command)
	{
	case '1':
		first();
		break;

	case '2':
		second();
		break;

	case 27:
		exit(0);
	default:
		cout << "Такой команды не существует \n\n";
	}
}

void first()
{
	while (1)
	{
		cout << "Меню: \n";
		cout << "1. Открыть структуру \n";
		cout << "2. Добавить структуру \n";
		cout << "3. Найти структуру по расчетному счету \n";
		cout << "4. Повторить платеж \n";
		cout << "5. Редактировать \n";
		cout << "6. Удалить \n";
		cout << "7. Сохранить в файл \n";
		cout << "8. Загрузить из файла \n";
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
			findMenu();
			break;

		case '4':
			repeatMenu();
			break;

		case '5':
			editMenu();
			break;

		case '6':
			removeMenu();
			break;

		case '7':
			major.save();
			break;

		case '8':
			major.load();
			break;

		case 27:
			exit(0);
		}
		system("@cls||clear");
	}
}

int second()
{
	ifstream fin("data.txt", ios::in | ios::binary);

	if (!fin)
	{
		cout << "Не удалось открыть файл \n";
		return 0;
	}

	fin.seekg(0, ios_base::end);
	int fileSize = fin.tellg();
	fin.seekg(0, ios_base::beg);

	char* buffer = new char[fileSize + 1];
	int max = 0, current = 0, current_start = 0, pos_start = 0, end = 0;

	for (int i = 0; (buffer[i] = fin.get()) != EOF; i++)
	{
		if (buffer[i] == '\r')
			buffer[i] = ' ';

		if (buffer[i] == ',' || buffer[i] == ';' || buffer[i] == ':' || buffer[i] == '-' || 
			buffer[i] == '"' || buffer[i] == '(' || buffer[i] == ')')
			current++;

		if (buffer[i] == '.' || buffer[i] == '?' || buffer[i] == '!')
		{
			if (current > max)
			{
				max = current;
				pos_start = current_start;
				end = i;
			}
			current = 0;
			current_start = i + 1;
		}
	}

	bool is_trimmed = 0;
	for (int i = pos_start; i <= end; i++) 
	{
		if (!is_trimmed) 
		{
			if (buffer[i] == ' ')
				continue;
			
			else
				is_trimmed = 1;
		}
		cout << buffer[i];
	}
	cout << "\n";
	return 0;
}

void findMenu() 
{
	if (major.isEmpty())
		return;

	int counter = 0;
	int acc;

	cout << "Введите расчетного счета плательщика: ";
	cin >> acc;
	cin.ignore();

	major.sort();

	for (size_t i = 0; i < major.getSize(); i++) 
	{
		int pacc = major.getStructure()[i]->getPA();
		if (pacc == acc)
		{
			cout << "\n";
			major.getStructure()[i]->print();
			counter++;
		}
	}

	if (!counter) 
	{
		system("@cls||clear");
		cout << "\n" << "Ничего не найдено" << "\n";
	}

	cout << "Нажмите любую клавишу\n";
	cin.get();
}

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

void repeatMenu() 
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

		cout << "Введите номер объекта: ";
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
		major.getStructure()[num - 1]->print();

		int PAorder = major.getStructure()[num - 1]->getPA();
		int BAorder = major.getStructure()[num - 1]->getBA();

		major.add(new Order(PAorder, BAorder));
		cout << "\nДобавлено";
		_getch();
		return;
	}
}