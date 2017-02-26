#ifndef STUD2_H
#define STUD2_H

#include "ABS_LIB.h"
#include "S2.h"

class Stud2 : public ABS_LIB
{
	int count;
	S2 *M;
public:
	Stud2();
	virtual ~Stud2();
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