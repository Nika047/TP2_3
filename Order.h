#pragma once

#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

class Order
{
public: 
	Order();

	Order(int* lines);

	void setPA();
	int getPA();
	void setBA();
	int getBA();
	void setAmount();
	int getAmount();
	void edit();
	void write(ofstream& file) const;

	void print();

	friend ofstream& operator<< (ofstream& file, const Order& object)
	{
		object.write(file);
		return file;
	}

private:
	int payers_account;
	int beneficiarys_account;
	int amount;
};