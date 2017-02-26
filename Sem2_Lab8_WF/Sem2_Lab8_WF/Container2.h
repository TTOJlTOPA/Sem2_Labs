#ifndef CONTAINER2_H
#define CONTAINER2_H

#include <iostream>
using namespace std;

struct Container2
{
	char Name[50];
	int data;
	Container2& operator = (const Container2& right);
	friend ostream& operator << (ostream& out, const Container2& elem);
	friend istream& operator >> (istream& in, Container2& elem);
};

#endif