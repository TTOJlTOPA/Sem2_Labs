#ifndef C_H
#define C_H

#include "Coding.h"
using namespace std;

class C : public Coding
{
protected:
	string oop;
	string imp;
	string func;
	string gen;
	string distr;
public:
	C();
	virtual void print();
};

#endif