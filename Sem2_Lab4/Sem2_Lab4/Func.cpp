#include "Func.h"

void exJoseph(int interval, int size)
{
	List <int> *list = new Circular<int>();
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		list->push(i + 1);
	}
	cout << "\t\t\t\tGAME BEGINS!!!" << endl;
	while (list->size() != 1)
	{
		j += (interval - 1);
		j %= list->size();
		cout << list->pop(j) << " eliminated!" << endl;
	}
	cout << "Winner is " << list->pop(0) << "!!!" << endl;
}