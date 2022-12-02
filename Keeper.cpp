#include "Keeper.h"
#include "Order.h"

Keeper::Keeper() {}

void Keeper::add(Order* element)
{
	Order** newStructure = new Order * [structureSize + 1];

	for (int i = 0; i < structureSize; i++)
		newStructure[i] = structure[i];

	newStructure[structureSize++] = element;
	delete[] structure;
	structure = newStructure;
}

void Keeper::remove(int number)
{
	Order** newStructure = new Order * [structureSize - 1];

	int num = 0;
	for (int i = 0; i < structureSize; i++)
	{
		if (i == number)
			continue;
		newStructure[num] = structure[i];
		num++;
	}
	delete[] structure;
	structure = newStructure;
	structureSize--;
}

void Keeper::save()
{
	ofstream out;
	out.open(fileName);

	if (out.is_open())
	{
		for (size_t i = 0; i < structureSize; i++)
			out << *structure[i] << "\n";

		cout << "Сохранено!\n";
	}

	else
		cout << "Не удалось открыть файл!";

	out.close();
	cout << "\nНажмите любую клавишу чтобы вернутся в меню\n";
	_getch();
}

void Keeper::load()
{
	string k;
	ifstream in(fileName);

	try
	{
		const int strCounter = 4;

		if (!in.is_open())
			throw std::runtime_error("Не удалось открыть файл");

		int counterK = count(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), '\n');
		if (counterK <= 0 || counterK % strCounter != 0)
			throw std::runtime_error("Файл пуст или поврежден");

		in.seekg(0);

		int strokCounter = 0;
		Order** newList = new Order * [(int)counterK / strCounter];
		string strok[strCounter];

		while (getline(in, k))
		{
			string str = k;

			strok[(strokCounter++) % strCounter] = str;

			int pos = strokCounter / strCounter - 1;

			if (strokCounter % strCounter == 0)
				newList[pos] = new Order(strok);
		}

		delete[]structure;
		structure = newList;
		structureSize = (int)counterK / strCounter;
		cout << "Успешно загруженo";
	}

	catch (std::runtime_error err)
	{
		cout << err.what() << "\n";
	}

	catch (...)
	{
		cout << "Неизвестная ошибка";
	}

	in.close();

	cout << "\n\nНажмите любую клавишу чтобы вернутся в меню \n";
	cin.get();
}

void Keeper::sort()
{
	Order* temp;
	for (size_t i = 0; i < structureSize - 1; i++)
	{
		for (size_t j = i + 1; j < structureSize; j++)
		{
			if (structure[i]->getPA() > structure[j]->getPA())
			{
				temp = structure[i];
				structure[i] = structure[j];
				structure[j] = temp;
			}
		}
	}
}

bool Keeper::isEmpty()
{
	if (structureSize > 0)
		return 0;

	cout << "Список пуст\n\n";
	cout << "Нажмите любую клавишу чтобы вернутся в меню \n";
	_getch();

	return 1;
}

void Keeper::print() 
{
	if (isEmpty())
		return;

	sort();

	for (size_t i = 0; i < getSize(); i++)
	{
		cout << "Номер: " << (i + 1) << "\n";
		getStructure()[i] -> print();
		cout << "\n";
	}

	cout << "Нажмите любую клавишу чтобы вернутся в меню \n";
	_getch();
}

Order** Keeper::getStructure()
{
	return structure;
}

int Keeper::getSize()
{
	return structureSize;
}

Keeper::~Keeper()
{
	delete[] structure;
}