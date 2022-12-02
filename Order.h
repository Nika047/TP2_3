#pragma once
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <conio.h>

using namespace std;

class Order
{
public: 
	Order();
	Order(int* lines);
	Order(int PA, int BA);

	void setPA();
	int getPA();
	void setBA();
	int getBA();
	void setAmount();
	int getAmount();
	void edit();
	void print();
	void write(ofstream& file) const;

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