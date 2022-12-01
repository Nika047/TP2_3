#include "Order.h"
#include <iomanip>

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

int Order::setPA() 
{
	cout << "��������� ���� �����������: ";
	cin >> payers_account;
	cin.get();
}

int Order::getPA() 
{
	return payers_account;
}

int Order::setBA() 
{
	cout << "��������� ���� ����������: ";
	cin >> beneficiarys_account;
	cin.get();
}

int Order::getBA() 
{
	return beneficiarys_account;
}

int Order::setAmount()
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
	while (true)
	{
		string commands[] = {
			"���",
			"�������",
			"���� ��������",
		};

		int line = menu("�������� ����: (< - ���������)", commands, 3);
		if (line < 0) return;

		switch (line)
		{
		case 0:
			setPA();

		case 1:
			setBA();

		case 2:
			setAmount();
		}
	}
}

string Order::toString()
{
	stringstream str;
	str << setw(36) << payers_account << setw(30) << beneficiarys_account << setw(16) << to_string(amount) << endl;

	return str.str();
}