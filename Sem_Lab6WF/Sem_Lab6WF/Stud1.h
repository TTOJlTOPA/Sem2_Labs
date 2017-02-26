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
	virtual ~Stud1();
	int Counter(ifstream& fin);
	virtual void Form(ABS_LIB* stud1, ABS_LIB* stud2);
	virtual void ReadData();
	virtual void WriteData();
	virtual void PutData(ostream& out);
	virtual int getCount();
	virtual char* getName(const int index);
	virtual double getPrice(const int index);
	virtual bool Search(char* name);
	virtual void Sort();
};

#endif