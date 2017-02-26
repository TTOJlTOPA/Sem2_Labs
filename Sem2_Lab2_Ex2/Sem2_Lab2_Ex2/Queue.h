#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <fstream>
using namespace std;

class Queue
{
	struct Link
	{
		int data;
		Link *next;
		//Link();
		Link(const int, Link*);
		Link(const Link&, Link*);
		~Link();
	} *rear, *front;
public:
	Queue();
	//Queue(const int);
	//Queue(const Queue&);
	~Queue();
	void push(const int);
	int pop();
	void showQueue();
	bool repeatCheck(const int);
};

bool primeCheck(const int);
bool palindromeCheck(const int);
void fInput(Queue&, Queue&);
void thirdQForm(Queue&, Queue&, Queue&);
void fOutput(Queue&);

#endif