#include "Stud2.h"

Stud2::Stud2()
{
	count = 0;
}
Stud2::~Stud2()
{
	delete[] M;
}
int Stud2::Counter(ifstream& fin)
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
void Stud2::Form(ABS_LIB* stud1, ABS_LIB* stud2)
{

}
void Stud2::ReadData()
{
	ifstream fin("InputStud2.txt", ios::binary);
	if (fin.is_open())
	{
		count = Counter(fin);
		M = new S2[count];
		for (int i = 0; i < count; i++)
		{
			fin >> M[i].Name;
		}
	}
	fin.close();
}
void Stud2::WriteData()
{

}
void Stud2::PutData(ostream& out)
{
	if (!count)
	{
		out << "Stud2 пуст!\n";
	}
	else
	{
		out << "\t\tStud2\r\n";
		out << "Имя" << "\t\t" << "Долг" << "\t\t" << "Дата сдачи\r\n";
		for (int i = 0; i < count; i++)
		{
			out << M[i].Name << "\r\n";
		}
	}
}
int Stud2::getCount()
{
	return count;
}
char* Stud2::getName(const int index)
{
	return M[index].Name;
}
double Stud2::getPrice(const int index)
{
	return 0;
}
bool Stud2::Search(char* name)
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
void Stud2::Sort()
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