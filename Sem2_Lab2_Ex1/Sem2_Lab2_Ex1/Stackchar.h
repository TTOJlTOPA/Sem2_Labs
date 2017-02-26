#ifndef STACKCHAR_H
#define STACKCHAR_H

#include <iostream>
using namespace std;

class Stackchar
{
	struct Link
	{
		char data;
		Link *next;
		Link(char, Link*);
		~Link();
	} *head;
public:
	Stackchar();
	~Stackchar();
	void push(char);
	char pop();
	char getHead();
	virtual bool stackStatus();
};

#endif