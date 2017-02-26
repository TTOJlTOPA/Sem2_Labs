#ifndef ABS_LIB_H
#define ABS_LIB_H

#include <iostream>
#include <fstream>
using namespace std;

class ABS_LIB
{
public:
	virtual void ReadData() = 0;
	virtual void WriteData() = 0;
	virtual void PutData(ostream& out) = 0;
	virtual void Form(ABS_LIB* stud1, ABS_LIB* stud2) = 0;
	virtual int getCount() = 0;
	virtual char* getName(const int index) = 0;
	virtual double getPrice(const int index) = 0;
	virtual bool Search(char* name) = 0;
	virtual void Sort() = 0;
};

#endif