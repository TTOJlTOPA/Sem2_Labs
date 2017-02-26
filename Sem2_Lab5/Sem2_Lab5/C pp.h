#ifndef C_PP_H
#define C_PP_H

#include "C.h"
using namespace std;

class Cpp : public C // ?? т.к. C не является подмножеством C++
{
protected:
	string refl;
public:
	Cpp();
	virtual void print();
};

#endif