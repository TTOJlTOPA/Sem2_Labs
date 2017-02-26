#include "List.h"

List::Link::Link(char *nm)
{
	strcpy(name, nm);
	next = 0;
	prev = 0;
}
List::Link::~Link()
{} //!!!!!!!!!!!!!!!!!
List::List()
{
	head = 0;
	tail = 0;
}
List::~List()
{} //?????????????????
void List::push(char *nm)
{
	Link *tmp = new Link(nm);
	tmp->next = head;
	tmp->prev = tail;
	if (tail)
	{
		tmp->prev->next = tmp;
		head->prev = tmp;
	}
	else
	{
		head = tmp;
	}
	tail = tmp;
	tail->next = head;
}
char* List::pop(Link* out, char *name)
{
	out->next->prev = out->prev;
	if (out->prev != 0)
	{
		out->prev->next = out->next;
	}
	if (out == head)
	{
		head = out->next;
	}
	if (out == tail)
	{
		tail = out->prev;
	}
	strcpy(name, out->name);
	delete out;
	return name;
}
void List::exJoseph(const int m, int& n)
{
	char name[20];
	Link *tmp = head, *tmpnext;
	while (tmp->next != tmp)
	{
		if (m % n == 0)
		{
			tmp = tmp->prev;
		}
		else
		{
			for (int i = 0; i < (m % n) - 1; i++)
			{
				tmp = tmp->next;
			}
		}
		if (tmp->next != 0)
		{
			tmpnext = tmp->next;
		}
		cout << pop(tmp, name) << " eliminated!" << endl;
		--n;
		tmp = tmpnext;
	}
	cout << "Winner is " << tmp->name << "!!!" << endl;
}