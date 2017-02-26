#ifndef DATA_H
#define DATA_H

#include "Fanat3.h"
using namespace std;

template <class T>
class Data1
{
	T* arr;
	int count;
public:
	Data1();
	Data1(const Data1<T>& init);
	~Data1();
	int GetCount();
	void Sort();
	void SortD();
	T& operator [] (int index);
	void Sum(Data1<Fanat1>& fan1, Data1<Fanat2>& fan2);
	int Search(char* name);
	template <class Type>
	friend int Check(char* fan, Data1<Type>& arrfans);
	template <class Type>
	friend istream& operator >> (istream& in, Data1<Type>& Data1);
	template <class Type>
	friend ostream& operator << (ostream& out, const Data1<Type>& Data1);
};

template <class T>
Data1<T>::Data1()
{
	arr = NULL;
	count = 0;
}
template <class T>
Data1<T>::Data1(const Data1<T>& init)
{
	count = init.count;
	arr = new T[count];
	for (int i = 0; i < count; i++)
	{
		arr[i] = init.arr[i];
	}
}
template <class T>
Data1<T>::~Data1()
{
	if (arr)
	{
		delete[] arr;
	}
}
template <class T>
int Data1<T>::GetCount()
{
	return count;
}
template <class T>
void Data1<T>::Sort()
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (strcmp(arr[j].Name, arr[j + 1].Name) > 0)
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
template <class T>
void Data1<T>::SortD()
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (strcmp(arr[j].Name, arr[j + 1].Name) < 0)
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
template <class T>
T& Data1<T>::operator [] (int index)
{
	if (index >= 0 && index <= count)
	{
		return arr[index];
	}
	else
	{
		cout << "Invalid index!!!" << endl;
	}
}
void Data1<Fanat3>::Sum(Data1<Fanat1>& fan1, Data1<Fanat2>& fan2)
{
	int tmpcount = 0, tmp;
	for (int i = 0; i < fan1.GetCount(); i++)
	{
		if (Check(fan1[i].Name, fan2) >= 0)
		{
			tmpcount++;
		}
	}
	count = fan1.GetCount() + fan2.GetCount() - tmpcount;
	arr = new Fanat3[count];
	tmpcount = 0;
	for (int i = 0; i < fan1.GetCount(); i++)
	{
		tmp = Check(fan1[i].Name, fan2);
		if (tmp >= 0)
		{
			strcpy(arr[tmpcount].Name, fan1[i].Name);
			strcpy(arr[tmpcount].Nationality, fan1[i].Nationality);
			arr[tmpcount].Year = fan1[i].Year;
			arr[tmpcount].Code = fan2[tmp].Code;
			arr[tmpcount].N = fan1[i].N + fan2[tmp].N;
			tmpcount++;
		}
		else
		{
			strcpy(arr[tmpcount].Name, fan1[i].Name);
			strcpy(arr[tmpcount].Nationality, fan1[i].Nationality);
			arr[tmpcount].Year = fan1[i].Year;
			arr[tmpcount].Code = 0;
			arr[tmpcount].N = fan1[i].N;
			tmpcount++;
		}
	}
	for (int i = 0; i < fan2.GetCount(); i++)
	{
		tmp = Check(fan2[i].Name, fan1);
		if (tmp < 0)
		{
			strcpy(arr[tmpcount].Name, fan2[i].Name);
			strcpy(arr[tmpcount].Nationality, "");
			arr[tmpcount].Year = 0;
			arr[tmpcount].Code = fan2[i].Code;
			arr[tmpcount].N = fan2[i].N;
			tmpcount++;
		}
	}
}
template <class T>
int Data1<T>::Search(char* name)
{
	for (int i = 0; i < GetCount(); i++)
	{
		if (strcmp(name, arr[i].Name) == 0)
		{
			return i;
		}
	}
	return -1;
}
template <class T>
int Check(char* fan, Data1<T>& arrfans)
{
	for (int i = 0; i < arrfans.GetCount(); i++)
	{
		if (strcmp(fan, arrfans[i].Name) == 0)
		{
			return i;
		}
	}
	return -1;
}
template <class T>
istream& operator >> (istream& in, Data1<T>& Data1)
{
	char buf[100];
	in.getline(buf, 100);
	Data1.count = atoi(buf);
	Data1.arr = new T[Data1.count];
	for (int i = 0; i < Data1.count; i++)
	{
		in >> Data1.arr[i];
	}
	return in;
}
template <class T>
ostream& operator << (ostream& out, const Data1<T>& Data1)
{
	for (int i = 0; i < Data1.count; i++)
	{
		out << Data1.arr[i] << "\n";
	}
	return out;
}

#endif