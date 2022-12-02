#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include "Order.h"

using namespace std;

class Keeper
{
public:
	Keeper();

	bool isEmpty();
	int getSize();
	void save();
	void load();
	void sort();
	void print();
	void remove(int number);
	void add(Order* element);

	Order** getStructure();

	~Keeper();

	friend const bool operator! (Keeper& major)
	{
		return (bool)major.getSize();
	}

private:
	Order** structure = {};
	int structureSize = 0;
	string fileName = "struct.txt";
};