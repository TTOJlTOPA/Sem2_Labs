#ifndef STUD3_H
#define STUD3_H

#include "ABS_LIB.h"
#include "S3.h"
#include "Stud1.h"
#include "Stud2.h"

class Stud3 : public ABS_LIB
{
	int count;
	S3 *M;
public:
	Stud3();
	virtual ~Stud3();
	void addStud3(char* name, double price);
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