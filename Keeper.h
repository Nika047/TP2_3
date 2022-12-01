#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "Order.h"

using namespace std;

class Keeper
{
public:
	Keeper();

	void add(Order* element);
	void remove(int number);
	void save();
	void load(); //????????
	void sort();
	void print();
	void printHead();
	bool isEmpty();

	Order** getStructure();

	int getSize();

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