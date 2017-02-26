#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "Abstract.h"

template <typename T>
class Circular : public List <T>
{
	struct Link
	{
		T data;
		Link *next;
		Link(T);
		~Link();
	} *front, *back;
public:
	Circular();
	~Circular();
	void push(T);
	T pop(int);
	bool empty();
	int size();
};

#endif