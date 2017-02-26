#ifndef STUD1_H
#define STUD1_H

#include "ABS_LIB.h"
#include "S1.h"

class Stud1 : public ABS_LIB
{
	int count;
	S1 *M;
public:
	Stud1();
	~Stud1();
	void addStud1(char* name, double price);
};

#endif