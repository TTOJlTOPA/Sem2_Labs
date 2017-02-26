#ifndef FANAT3_H
#define FANAT3_H

#include "Fanat1.h"
#include "Fanat2.h"

struct Fanat3
{
	char Nationality[20];
	char Name[45];
	int Year;
	int Code;
	int N;
	Fanat3();
	Fanat3(char* nation, char* name, int year, int code, int n);
	Fanat3(const Fanat3& init);
	~Fanat3();
	Fanat3& operator = (const Fanat3& right);
	friend istream& operator >> (istream& in, Fanat3& data);
	friend ostream& operator << (ostream& out, const Fanat3& data);
};

#endif