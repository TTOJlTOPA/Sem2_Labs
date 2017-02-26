#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include "Container1.h"
#include "Container2.h"
#include "Container3.h"
using namespace std;

template <class T>
class CONTAINER
{
	int count;
	T* M;
public:
	CONTAINER();
	CONTAINER(int size);
	CONTAINER(CONTAINER<T>& m);
	~CONTAINER();
	void Sort();
	void Search(ostream& out, int date);
	int getCount();
	CONTAINER<Container3>& CreateContainer3(CONTAINER<Container1>& first, CONTAINER<Container2>& second);
	CONTAINER<T>& operator = (const CONTAINER<T>& right);
	T& operator [] (int index);
	template <class Type>
	friend istream& operator >> (istream& in, CONTAINER<Type>& forin);
	template <class Type>
	friend ostream& operator << (ostream& out, CONTAINER<Type>& forout);
};

template <class T>
CONTAINER<T>::CONTAINER()
{
	count = 0;
}
template <class T>
CONTAINER<T>::CONTAINER(int size)
{
	count = size;
	M = new T[size];
}
template <class T>
CONTAINER<T>::CONTAINER(CONTAINER<T>& m)
{
	count = m.count;
	M = new T[count];
	for (int i = 0; i < count; i++)
	{
		M[i] = m[i];
	}
}
template <class T>
CONTAINER<T>::~CONTAINER()
{
	if (count != 0)
	{
		delete[] M;
	}
}
template <>
void CONTAINER<Container2>::Sort()
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (M[j].data < M[j + 1].data)
			{
				swap(M[j], M[j + 1]);
			}
		}
	}
}
template <>
void CONTAINER<Container2>::Search(ostream& out, int date)
{
	for (int i = 0; i < count; i++)
	{
		if (M[i].data > date)
		{
			out << M[i];
		}
	}
}
template <class T>
int CONTAINER<T>::getCount()
{
	return count;
}
template <>
CONTAINER<Container3>& CONTAINER<Container3>::CreateContainer3(CONTAINER<Container1>& first, CONTAINER<Container2>& second)
{
	Container3* tmp;
	bool flag;
	for (int i = 0; i < first.getCount(); i++)
	{
		flag = false;
		for (int j = 0; j < second.getCount(); j++)
		{
			if (!strcmp(first[i].Name, second[i].Name))
			{
				flag = true;
			}
		}
		if (!flag)
		{
			if (count != 0)
			{
				tmp = new Container3[count];
				for (int k = 0; k < count; k++)
				{
					tmp[k] = M[k];
				}
				delete[] M;
			}
			count++;
			M = new Container3[count];
			if (count != 1)
			{
				for (int k = 0; k < count; k++)
				{
					M[k] = tmp[k];
					M[k].Price = 0;
				}
				delete[] tmp;
			}
			M[count - 1].Price = 0;
			strcpy(M[count - 1].Name, first[i].Name);
			strcpy(M[count - 1].Addr, first[i].Addr);
		}
	}
	return *this;
}
template <class T>
CONTAINER<T>& CONTAINER<T>::operator = (const CONTAINER<T>& right)
{
	if (this != &right)
	{
		if (count != 0)
		{
			delete[] M;
		}
		count = right.count;
		M = new T[count];
		for (int i = 0; i < count; i++)
		{
			M[i] = right.M[i];
		}
	}
	return *this;
}
template <class T>
T& CONTAINER<T>::operator [] (int index)
{
	return M[index];
}
template <class T>
istream& operator >> (istream& in, CONTAINER<T>& forin)
{
	for (int i = 0; i < forin.count; i++)
	{
		in >> forin[i];
	}
	return in;
}
template <class T>
ostream& operator << (ostream& out, CONTAINER<T>& forout)
{
	for (int i = 0; i < forout.count; i++)
	{
		out << forout[i];
	}
	return out;
}

#endif