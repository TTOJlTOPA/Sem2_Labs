#include "Circular.h"

template <typename T>
Circular<T>::Link::Link(T dat)
{
	data = dat;
	//next = front;
}
template <typename T>
Circular<T>::Link::~Link()
{}

template <typename T>
Circular<T>::Circular()
{
	front = 0;
	back = 0;
}
template <typename T>
Circular<T>::~Circular()
{
	while (!empty())
	{
		this->pop(0);
	}
}
template <typename T>
void Circular<T>::push(T dat)
{
	Link *tmp = new Link(dat);
	//tmp->next = front;
	if (!empty())
	{
		back->next = tmp;
	}
	else
	{
		front = tmp;
	}
	back = tmp;
	back->next = front;
}
template <typename T>
T Circular<T>::pop(int index)
{
	Link *tmp, *tmpback;
	T ret;
	tmp = front;
	for (int i = 0; i < index - 1; i++)
	{
		tmp = tmp->next;//??
	}
	if (index > 0)
	{
		tmpback = tmp->next;
		tmp->next = tmp->next->next;
		tmp = tmpback;
	}
	if (index == -1)
	{
		tmp = back;
	}
	if (tmp == front)
	{
		front = tmp->next;
		back->next = front;
	}
	if (tmp == back)
	{
		tmpback = front;
		for (int i = 0; i < size() - 1; i++)
		{
			tmpback = tmpback->next;
		}
		back = tmpback;
		tmpback->next = front;
	}
	ret = tmp->data;
	delete tmp;
	return ret;
}
template <typename T>
bool Circular<T>::empty()
{
	if (front == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
int Circular<T>::size()
{
	int size = 1;
	Link *tmp;
	if (empty())
	{
		return 0;
	}
	else
	{
		tmp = front;
		tmp = tmp->next;
		while (tmp != front)
		{
			tmp = tmp->next;
			size++;
		}
	}
	return size;
}