#ifndef S1_H
#define S1_H

#include <iostream>
using namespace std;

struct S1
{
	char Name[50];
	double Price;
	S1();
	S1(char *name, double price);
	S1(const S1& init);
	~S1();
	const S1& operator = (const S1& right);
	friend ostream& operator << (ostream& out, const S1 obj);
};

#endif