#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class List
{
	struct Link
	{
		char name[20];
		Link *next, *prev;
		Link(char*);
		~Link();
	} *head, *tail;
public:
	List();
	~List();
	void push(char*);
	char* pop(Link*, char*);
	void exJoseph(const int, int&);
};

#endif