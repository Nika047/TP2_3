#pragma once

#include <string>
#include <sstream>
#include "utils.cpp"

using namespace std;

class Order
{
public: 
	Order();

	Order(int* lines);

	int setPA();
	int getPA();
	int setBA();
	int getBA();
	int setAmount();
	int getAmount();
	void edit();
	string toString();

	friend std::ofstream& operator<< (std::ofstream& file, const Order& order)
	{
		file << order.payers_account << "\n";
		file << order.beneficiarys_account << "\n";
		file << order.amount << "\n";
		file << "\n";

		return file;
	}

private:
	int payers_account;
	int beneficiarys_account;
	int amount;
};

