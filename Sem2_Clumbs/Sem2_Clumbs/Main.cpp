#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Clumbs.h"
int main()
{
	ifstream fin("Data.txt");
	vector <Clumbs> data(input(fin));
	Sort(data);
	Search(data);
	Everywhere(data);
	SearchNum(data);
	Change(data);
	return 0;

}