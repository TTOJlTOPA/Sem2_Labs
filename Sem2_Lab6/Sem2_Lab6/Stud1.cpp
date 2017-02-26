#include "Stud1.h"

Stud1::Stud1()
{
	count = 0;
}
Stud1::~Stud1()
{
	delete[] M;
}
void Stud1::addStud1(char* name, double price)
{
	S1 *tmp = new S1[count];
	if (count > 0)
	{
		for (int i = 0; i < count; i++)
		{
			tmp[i] = M[i];
		}
	}
	delete[] M;
	count++;
	M = new S1[count];
	if (count > 1)
	{
		for (int i = 0; i < count - 1; i++)
		{
			M[i] = tmp[i];
		}
	}
	delete[] tmp;
	M[count - 1] = S1(name, price);
}