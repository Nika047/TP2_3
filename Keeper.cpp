#include "Keeper.h"
#include <conio.h>
#include "Order.h"

Keeper::Keeper() {}

void Keeper::add(Order* element)
{
	Order** newList = new Order * [structureSize + 1];

	for (int i = 0; i < structureSize; i++)
		newList[i] = structure[i];

	newList[structureSize++] = element;
	delete[] structure;
	structure = newList;
}

void Keeper::remove(int number)
{
	Order** newList = new Order * [structureSize - 1];

	int index = 0;
	for (int i = 0; i < structureSize; i++)
	{
		if (i == number)
			continue;
		newList[index] = structure[i];
		index++;
	}
	delete[] structure;
	structure = newList;
	structureSize--;
}

void Keeper::save()
{
	ofstream out;
	out.open(fileName);

	if (out.is_open())
	{
		out << structureSize << "\n";
		for (size_t i = 0; i < structureSize; i++)
		{
			out << *structure[i];
			out << "\n";
		}
		cout << "���������!\n";
	}

	else
		cout << "�� ������� ������� ����!";

	out.close();
	cout << endl << "������� ����� ������� ����� �������� � ����\n";
	_getch();
}

void Keeper::load() // ???????????????
{
	string line;
	ifstream in(fileName);

	try
	{
		if (!in.is_open())
			throw std::runtime_error("�� ������� ������� ����");

		getline(in, line);

		int structCount = stoi(line);
		if (structCount <= 0)
			throw std::runtime_error("���� ���� ��� ���������");

		int counter = 0;
		Order** newList = new Order * [structCount];

//			const int strNums = 6;
//
//			if (!in.is_open()) throw std::runtime_error("�� ������� ������� ����.");
//
//			int numberOfLines = count(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), '\n'); // ������� ���������� ����� � �����
//			if (numberOfLines <= 0 || numberOfLines % strNums != 0) throw std::runtime_error("���� ���������!");
//
//			in.seekg(0);
//
//			int lineNum = 0;
//			Note **newList = new Note*[(int) numberOfLines / strNums];
//			string lines[strNums];

		while (getline(in, line))
		{
			if (string("������") == line)
				newList[counter++] = new Furniture(in);

			if (string("��������") == line)
				newList[counter++] = new Worker(in);

			if (string("������") == line)
				newList[counter++] = new Car(in);
		}
			//			{
			//				string str = line;
			//
			//				lines[(lineNum++) % strNums] = str;
			//				
			//				int pos = lineNum / strNums - 1;
			//
			//				if (lineNum % strNums == 0) {
			//					newList[pos] = new Note(lines);
			//				}
			//			}

		delete[]structure;
		structure = newList;
		structureSize = structCount;
		cout << "������� ��������(�) " << structureSize << " ������(��)\n";
	}

	catch (std::runtime_error err)
	{
		cout << err.what() << "\n";
	}

	catch (...)
	{
		cout << "����������� ������";
	}

	in.close();
	cout << "\n������� ����� ������� ����� �������� � ���� \n";
	_getch();
} // 
//???????????

void Keeper::sort()
{
	Order* temp;
	for (size_t i = 0; i < structureSize - 1; i++)
	{
		for (size_t j = i + 1; j < structureSize; j++)
		{
			int cmp = _stricmp(structure[i]->getPA().c_str(), structure[j]->getPA().c_str());
			if (_stricmp(structure[i]->getPA().c_str(), structure[j]->getPA().c_str()) > 0)
			{
				temp = structure[i];
				structure[i] = structure[j];
				structure[j] = temp;
			}
		}
	}
}
//?????????????

void Keeper::printHead() 
{
	cout << "\033[47;30m" << setw(36) << "���" << setw(30) << "�������" << setw(16) << "���� ��������" << "\033[0m" << endl;
}
//?????????????///

bool Keeper::isEmpty()
{
	if (structureSize > 0)
		return 0;

	cout << "������ ����\n\n";
	cout << "������� ����� ������� ����� �������� � ���� \n";
	_getch();

	return 1;
}

void Keeper::print() 
{
	if (isEmpty())
		return;

	sort();
	printHead();

	for (size_t i = 0; i < getSize(); i++)
	{
		//cout << getStructure()[i] -> toString();
		structure[i]->toString();
		cout << "\n";
	}

	cout << "\n������� ����� ������� \n";
	_getch();
}

Order** Keeper::getStructure()
{
	return this->structure;
	//return structure;
}

int Keeper::getSize()
{
	return this->structureSize;
	//return structureSize;
}

Keeper::~Keeper()
{
	delete[] structure;
}