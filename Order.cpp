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
	cout << "��������� ���� �����������: ";
	cin >> payers_account;
	cin.get();
}

int Order::getPA() 
{
	return payers_account;
}

void Order::setBA()
{
	cout << "��������� ���� ����������: ";
	cin >> beneficiarys_account;
	cin.get();
}

int Order::getBA() 
{
	return beneficiarys_account;
}

void Order::setAmount()
{
	cout << "������� ������������� ����� � ������: ";
	cin >> amount;
	cin.get();
}

int Order::getAmount()
{
	return amount;
}

void Order::edit() 
{
	setPA();
	setBA();
	setAmount();
	cout << "\n";
}

void Order::print()
{
	cout << "��������� ���� �����������: " << payers_account << "\n";
	cout << "��������� ���� ����������: " << beneficiarys_account << "\n";
	cout << "������������� ����� � ������: " << amount << "\n";
}

void Order::write(ofstream& file) const
{
	file << payers_account << "\n";
	file << beneficiarys_account << "\n";
	file << amount << "\n";
}