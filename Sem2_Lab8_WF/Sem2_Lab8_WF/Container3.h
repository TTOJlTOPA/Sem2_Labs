#ifndef CONTAINER3_H
#define CONTAINER3_H

#include <iostream>
using namespace std;

struct Container3
{
	char Name[50];
	char Addr[50];
	double Price;
	Container3& operator = (const Container3& right);
	friend ostream& operator << (ostream& out, const Container3& elem);
	friend istream& operator >> (istream& in, Container3& elem);
};

#endif