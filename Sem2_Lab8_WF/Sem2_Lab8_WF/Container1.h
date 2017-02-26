#ifndef CONTAINER1_H
#define CONTAINER1_H

#include <iostream>
using namespace std;

struct Container1
{
	char Name[50];
	char Addr[50];
	Container1& operator = (const Container1& right);
	friend ostream& operator << (ostream& out, const Container1& elem);
	friend istream& operator >> (istream& in, Container1& elem);
};

#endif