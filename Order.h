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
	string toString();

	void print();

	friend ofstream& operator<< (ofstream& file, const Order& object)
	{
		object.write(file);
		return file;

		//out << object.payers_account << "\n";
		//out << object.beneficiarys_account << "\n";
		//out << object.amount << "\n";
	}

	//friend std::ofstream& operator<< (std::ofstream& file, const Order& note) 
	//{
	//	file << note.payers_account << "\n";
	//	file << note.beneficiarys_account << "\n";
	//	file << note.amount << "\n";

	//	return file;
	//}

private:
	int payers_account;
	int beneficiarys_account;
	int amount;
};