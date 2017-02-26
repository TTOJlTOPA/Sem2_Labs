#include "Data.h"
#include <fstream>

int main()
{
	Data1<Fanat1> fan1;
	Data1<Fanat2> fan2;
	Data1<Fanat3> fan3;
	ifstream fin1("Fanat1.txt");
	ifstream fin2("Fanat2.txt");
	ofstream fout("SumFans.txt");
	if (fin1.is_open())
	{
		fin1 >> fan1;
	}
	else
	{
		cout << "Fanat1.txt couldn't be open!!!" << endl;
		return -1;
	}
	if (fin2.is_open())
	{
		fin2 >> fan2;
	}
	else
	{
		cout << "Fanat2.txt couldn't be open!!!" << endl;
		return -1;
	}
	cout << "Fanat1:\n" << fan1 << "\nFanat2:\n" << fan2;
	cout << fan1[1];
	cout << fan1.GetCount() << endl;
	fan1.Sort();
	fan2.SortD();
	cout << "Fanat1 Sort:\n" << fan1 << "Fanat2 SortD:\n" << fan2;
	fan3.Sum(fan1, fan2);
	cout << "Fanat3:\n";
	cout << fan3;
	fout << fan3;
	fin1.close();
	fin2.close();
	fout.close();
}