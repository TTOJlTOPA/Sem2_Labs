#ifndef STACKDOUBLE_H
#define STACKDOUBLE_H

#include <iostream>
using namespace std;

class Stackdouble
{
	struct Link
	{
		double data;
		Link *next;
		Link(double, Link*);
		~Link();
	} *head;
public:
	Stackdouble();
	~Stackdouble();
	void push(double);
	double pop();
	virtual bool stackStatus();
};

#endif