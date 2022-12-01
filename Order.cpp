#include "Order.h"
#include <iomanip>
#include <iostream>
#include <conio.h>

Order::Order() 
{
	setPA();
	setBA();
	setAmount();
}

Order::Order(int* lines) 
{
	payers_account = lines[0];
	beneficiarys_account = lines[1];
	amount = lines[2];
}

void Order::setPA() 
{
	cout << "Расчетный счет плательщика: ";
	cin >> payers_account;
	cin.get();
}

int Order::getPA() 
{
	return payers_account;
}

void Order::setBA()
{
	cout << "Расчетный счет получателя: ";
	cin >> beneficiarys_account;
	cin.get();
}

int Order::getBA() 
{
	return beneficiarys_account;
}

void Order::setAmount()
{
	cout << "Введите перечисляемую сумму в рублях: ";
	cin >> amount;
	cin.get();
}

int Order::getAmount()
{
	return amount;
}

void Order::edit() 
{
	while (1)
	{
		cout << "Меню: \n";
		cout << "1. Расчетный счет плательщика \n";
		cout << "2. Расчетный счет получателя \n";
		cout << "3. Перечисляемая сумма в рублях \n";
		cout << "ESC. Выход \n\n";
		cout << "Выберите нужное действие: ";

		char command = _getch();
		system("@cls||clear");

		switch (command)
		{
		case '1':
			setPA();

		case '2':
			setBA();

		case '3':
			setAmount();

		case 27:
			exit(0);

		default:
			return;
		}
		//system("@cls||clear");
	}
}

string Order::toString()
{
	stringstream str;
	str << setw(36) << payers_account << setw(30) << beneficiarys_account << setw(16) << to_string(amount) << endl;

	return str.str();
}

void Order::print()
{
	cout << "Расчетный счет плательщика: " << payers_account << "\n";
	cout << "Расчетный счет получателя: " << beneficiarys_account << "\n";;
	cout << "Перечисляемая сумма в рублях: " << amount << "\n";;
}

void Order::write(ofstream& file) const
{
	file << payers_account << "\n";
	file << beneficiarys_account << "\n";
	file << amount << "\n";
}