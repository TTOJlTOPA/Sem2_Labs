#include "Stud3.h"

Stud3::Stud3()
{
	count = 0;
}
Stud3::~Stud3()
{
	delete[] M;
}
void Stud3::addStud3(char* name, double price)
{
	S3 *tmp = new S3[count];
	if (count > 0)
	{
		for (int i = 0; i < count; i++)
		{
			tmp[i] = M[i];
		}
	}
	delete[] M;
	count++;
	M = new S3[count];
	if (count > 1)
	{
		for (int i = 0; i < count - 1; i++)
		{
			M[i] = tmp[i];
		}
	}
	delete[] tmp;
	M[count - 1] = S3(name, price);
}
void Stud3::Form(ABS_LIB* stud1, ABS_LIB* stud2)
{
	int sofstud1;
	sofstud1 = stud1->getCount();
	for (int i = 0; i < sofstud1; i++)
	{
		if (!stud2->Search(stud1->getName(i)))
		{
			addStud3(stud1->getName(i), stud1->getPrice(i));
		}
	}
}
void Stud3::ReadData()
{

}
void Stud3::WriteData()
{
	ofstream fout("Output.txt", ios::binary);
	if (fout.is_open() && count)
	{
		for (int i = 0; i < count; i++)
		{
			fout << M[i].Name << "\t\t" << M[i].Price << "\t\t" << M[i].ControlDate << "\n";
		}
	}
	fout.close();
}
void Stud3::PutData(ostream& out)
{
	if (!count)
	{
		out << "Stud3 пуст!\n";
	}
	else
	{
		out << "\t\tStud3\r\n";
		out << "Имя" << "\t\t" << "Долг" << "\t\t" << "Дата сдачи\r\n";
		for (int i = 0; i < count; i++)
		{
			out << M[i].Name << "\t\t" << M[i].Price << "\t\t" << M[i].ControlDate << "\r\n";
		}
	}
}
int Stud3::getCount()
{
	return count;
}
char* Stud3::getName(const int index)
{
	return M[index].Name;
}
double Stud3::getPrice(const int index)
{
	return M[index].Price;
}
bool Stud3::Search(char* name)
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
void Stud3::Sort()
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