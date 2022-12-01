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
		cout << "Сохранено!\n";
	}

	else
		cout << "Не удалось открыть файл!";

	out.close();
	cout << endl << "Нажмите любую клавишу чтобы вернутся в меню\n";
	_getch();
}

void Keeper::load()
{
	int line;
	ifstream in("struct.txt");

	try
	{
		const int strNums = 6;

		if (!in.is_open())
			throw std::runtime_error("Не удалось открыть файл");

		int numberOfLines = count(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), '\n');
		if (numberOfLines <= 0 || numberOfLines % strNums != 0)
			throw std::runtime_error("Файл пуст или поврежден");

		in.seekg(0);

		int lineNum = 0;
		Order** newList = new Order * [(int)numberOfLines / strNums];
		int lines[strNums];

		while (in >> line)
		{
			int str = line;

			lines[(lineNum++) % strNums] = str;

			int pos = lineNum / strNums - 1;

			if (lineNum % strNums == 0)
				newList[pos] = new Order(lines);
		}

		delete[]structure;
		structure = newList;
		structureSize = (int)numberOfLines / strNums;

		cout << "Успешно загруженo";
	}

	catch (std::runtime_error err)
	{
		cout << err.what() << endl;
	}

	catch (...)
	{
		cout << "Неизвестная ошибка";
	}

	in.close();

	cout << endl << "\nНажмите любую клавишу чтобы вернутся в меню \n";
	cin.get();
}

//void Keeper::load() // ???????????????
//{
//	string line;
//	ifstream in(fileName);
//
//	try
//	{
//		if (!in.is_open())
//			throw std::runtime_error("Не удалось открыть файл");
//
//		getline(in, line);
//
//		int structCount = stoi(line);
//		if (structCount <= 0)
//			throw std::runtime_error("Файл пуст или поврежден");
//
//		int counter = 0;
//		Order** newList = new Order * [structCount];
//
////			const int strNums = 6;
////
////			if (!in.is_open()) throw std::runtime_error("Не удалось открыть файл.");
////
////			int numberOfLines = count(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), '\n'); // считаем количесвто строк в файле
////			if (numberOfLines <= 0 || numberOfLines % strNums != 0) throw std::runtime_error("Файл поврежден!");
////
////			in.seekg(0);
////
////			int lineNum = 0;
////			Note **newList = new Note*[(int) numberOfLines / strNums];
////			string lines[strNums];
//
//		while (getline(in, line))
//		{
//			if (string("Мебель") == line)
//				newList[counter++] = new Order(in);
//		}
//			//			{
//			//				string str = line;
//			//
//			//				lines[(lineNum++) % strNums] = str;
//			//				
//			//				int pos = lineNum / strNums - 1;
//			//
//			//				if (lineNum % strNums == 0) {
//			//					newList[pos] = new Note(lines);
//			//				}
//			//			}
//
//		delete[]structure;
//		structure = newList;
//		structureSize = structCount;
//		cout << "Успешно загружен(о) " << structureSize << " объект(ов)\n";
//	}
//
//	catch (std::runtime_error err)
//	{
//		cout << err.what() << "\n";
//	}
//
//	catch (...)
//	{
//		cout << "Неизвестная ошибка";
//	}
//
//	in.close();
//	cout << "\nНажмите любую клавишу чтобы вернутся в меню \n";
//	_getch();
//} // 
//???????????

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
//?????????????

void Keeper::printHead() 
{
	cout << "\033[47;30m" << setw(36) << "ФИО" << setw(30) << "Телефон" << setw(16) << "День рождения" << "\033[0m" << endl;
}
//?????????????///

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
	printHead();

	for (size_t i = 0; i < getSize(); i++)
	{
		cout << getStructure()[i] -> toString();
		//structure[i]->toString();
		cout << "\n";
	}

	cout << "\nНажмите любую клавишу \n";
	_getch();
}



Order** Keeper::getStructure()
{
	//return this->structure;
	return structure;
}

int Keeper::getSize()
{
	//return this->structureSize;
	return structureSize;
}

Keeper::~Keeper()
{
	delete[] structure;
}