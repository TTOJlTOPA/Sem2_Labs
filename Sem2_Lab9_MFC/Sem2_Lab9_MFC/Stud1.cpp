#include "stdafx.h"
#include "Stud1.h"

Stud1::Stud1()
{
	count = 0;
}
Stud1::~Stud1()
{
	delete[] M;
}
int Stud1::Counter(ifstream& fin)
{
	int count = 0;
	char str[100];
	while (fin.getline(str, 100))
	{
		count++;
	}
	fin.clear();
	fin.seekg(0);
	return count;
}
void Stud1::Form(ABS_LIB* stud1, ABS_LIB* stud2)
{

}
void Stud1::ReadData()
{
	ifstream fin("InputStud1.txt", ios::binary);
	if (fin.is_open())
	{
		count = Counter(fin);
		M = new S1[count];
		for (int i = 0; i < count; i++)
		{
			fin >> M[i].Name >> M[i].Price;
		}
	}
	fin.close();
}
void Stud1::WriteData()
{

}
void Stud1::PutData(ostream& out)
{
	if (!count)
	{
		out << "Stud1 пуст!\n";
	}
	else
	{
		out << "\t\tStud1\r\n";
		out << "Имя" << "\t\t" << "Долг" << "\t\t" << "Дата сдачи\r\n";
		for (int i = 0; i < count; i++)
		{
			out << M[i].Name << "\t\t" << M[i].Price << "\r\n";
		}
	}
}
int Stud1::getCount()
{
	return count;
}
char* Stud1::getName(const int index)
{
	return M[index].Name;
}
double Stud1::getPrice(const int index)
{
	return M[index].Price;
}
bool Stud1::Search(char* name)
{
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(M[i].Name, name))
		{
			return true;
		}
	}
	return false;
}
void Stud1::Sort()
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (M[j].Name[0] > M[j + 1].Name[0])
			{
				swap(M[j], M[j + 1]);
			}
		}
	}
}