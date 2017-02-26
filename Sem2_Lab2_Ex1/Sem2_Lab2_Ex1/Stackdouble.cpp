#include "Stackdouble.h"

Stackdouble::Link::Link(double dat, Link *nxt)
{
	data = dat;
	next = nxt;
}
Stackdouble::Link::~Link()
{}

Stackdouble::Stackdouble()
{
	head = 0;
}
Stackdouble::~Stackdouble()
{
	while (head != 0)
	{
		pop();
	}
}
void Stackdouble::push(double dat)
{
	Link *tmp = new Link(dat, head);
	if (head != 0)
	{
		tmp->next = head;
	}
	head = tmp;
}
double Stackdouble::pop()
{
	double ret = head->data;
	Link *tmp = head;
	head = head->next;
	delete tmp;
	return ret;
}
bool Stackdouble::stackStatus()
{
	if (head == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}