#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
using namespace std;

class Human
{
protected:
	char name[50];
	int age;
	int weight;
public:
	Human();
	Human(char* iname, int iage, int iweight);
	Human(const Human& init);
	virtual ~Human();
	virtual void Print(ostream& out);
};

#endif