#include "Stackchar.h"

Stackchar::Link::Link(char dat, Link *nxt)
{
	data = dat;
	next = nxt;
}
Stackchar::Link::~Link()
{}

Stackchar::Stackchar()
{
	head = 0;
}
Stackchar::~Stackchar()
{
	while (head != 0)
	{
		pop();
	}
}
void Stackchar::push(char dat)
{
	Link *tmp = new Link(dat, head);
	if (head != 0)
	{
		tmp->next = head;
	}
	head = tmp;
}
char Stackchar::pop()
{
	char ret = head->data;
	Link *tmp = head;
	head = head->next;
	delete tmp;
	return ret;
}
char Stackchar::getHead()
{
	return head->data;
}
bool Stackchar::stackStatus()
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