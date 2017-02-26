#include "Func.h"

void exJoseph(const int interval, int& size)
{
	list <int> lst;
	//char name[20];
	int num;
	for (int i = 0; i < size; i++)
	{
		lst.push_back(i+1);
	}
	list<int>::iterator iter = lst.begin(), tmpiter;
	while (lst.size() != 1)
	{
		if (interval % size == 0)
		{
			tmpiter = iter;
			if (tmpiter == lst.begin())
			{
				tmpiter = lst.end();
			}
			else
			{
				iter--;
			}
		}
		else
		{
			for (int i = 0; i < (interval % size) - 1; i++)
			{
				tmpiter = iter;
				tmpiter++;
				if (tmpiter == lst.end())
				{
					iter = lst.begin();
				}
				else
				{
					iter++;
				}
			}
			tmpiter = iter;
			tmpiter++;
		}
		if (tmpiter == lst.end())
		{
			lst.pop_back();
			iter = lst.begin();
		}
		else
		{
			//cout << iter << " elimitated!" << endl;
			iter = lst.erase(iter);
		}
		size--;
	}
	cout << "Winner is " << lst.back() << "!!!" << endl;
}