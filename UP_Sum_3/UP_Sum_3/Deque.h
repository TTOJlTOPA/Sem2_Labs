#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Deque
{
	vector<T> data;
public:
	Deque();
	Deque(int size);
	Deque(const Deque<T>& init);
	~Deque();
	bool isEmpty();
	T front();
	T back();
	void push_front(T dat);
	void push_back(T dat);
	void pop_front();
	void pop_back();
	size_t size();
	void print(ostream& out);
	T sum();
};

template <class T>
Deque<T>::Deque()
{
	data = vector<T>;
}
template <class T>
Deque<T>::Deque(int size)
{
	for (int i = 0; i < size; i++)
	{
		data.push_back(rand() % 100);
	}
}
template <>
Deque<double>::Deque(int size)
{
	for (int i = 0; i < size; i++)
	{
		data.push_back((rand() % 1000) / 10);
	}
}
template <class T>
Deque<T>::Deque(const Deque<T>& init)
{
	data = init.data;
}
template <class T>
Deque<T>::~Deque()
{
	while (!isEmpty())
	{
		pop_back();
	}
}
template <class T>
bool Deque<T>::isEmpty()
{
	return data.empty();
}
template <class T>
T Deque<T>::front()
{
	return data.front();
}
template <class T>
T Deque<T>::back()
{
	return data.back();
}
template <class T>
void Deque<T>::push_front(T dat)
{
	vector<T>::iterator iter;
	iter = data.begin();
	data.insert(iter, dat);
}
template <class T>
void Deque<T>::push_back(T dat)
{
	data.push_back(dat);
}
template <class T>
void Deque<T>::pop_front()
{
	vector<T>::iterator iter;
	iter = data.begin();
	data.erase(iter);
}
template <class T>
void Deque<T>::pop_back()
{
	data.pop_back();
}
template <class T>
size_t Deque<T>::size()
{
	return data.size();
}
template <class T>
void Deque<T>::print(ostream& out)
{
	for (auto i = data.begin(); i != data.end(); i++)
	{
		out << *i << ' ';
	}
	out << endl;
}
template <class T>
T Deque<T>::sum()
{
	T res = 0;
	for (auto i = data.begin(); i != data.end(); i++)
	{
		res += *i;
	}
	return res;
}

#endif