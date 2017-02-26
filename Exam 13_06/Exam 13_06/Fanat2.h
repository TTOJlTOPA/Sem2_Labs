#ifndef FANAT2_H
#define FANAT2_H

#include <iostream>
using namespace std;

struct Fanat2
{
	char Name[45];
	int Code;
	int N;
	Fanat2();
	Fanat2(char* name, int code, int n);
	Fanat2(const Fanat2& init);
	~Fanat2();
	Fanat2& operator = (const Fanat2& right);
	friend istream& operator >> (istream& in, Fanat2& data);
	friend ostream& operator << (ostream& out, const Fanat2& data);
};

#endif