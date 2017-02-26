#ifndef FANAT1_H
#define FANAT1_H

#include <iostream>
using namespace std;

struct Fanat1
{
	char Name[45];
	char Nationality[20];
	int Year;
	int N;
	Fanat1();
	Fanat1(char* name, char* nation, int year, int n);
	Fanat1(const Fanat1& init);
	~Fanat1();
	Fanat1& operator = (const Fanat1& right);
	friend istream& operator >> (istream& in, Fanat1& data);
	friend ostream& operator << (ostream& out, const Fanat1& data);
};

#endif