#ifndef ABSTRACT_H
#define ABSTRACT_H

#include <iostream>
using namespace std;

template <typename T>
class List
{
public:
	//List();
	//virtual ~List() = 0;
	virtual void push(T) = 0;
	virtual T pop(int) = 0;
	virtual bool empty() = 0;
	virtual int size() = 0;
};

#endif