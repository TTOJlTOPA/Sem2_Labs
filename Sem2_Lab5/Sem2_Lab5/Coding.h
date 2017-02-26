#ifndef CODING_H
#define CODING_H

#include <iostream>
#include <string>
using namespace std;

class Coding
{
protected:
	string name;
	string creator;
	int year;
public:
	virtual void print() = 0;
};

#endif