#include "Func.h"

int main()
{
	int size, interval, j;
	cout << "Enter number of participants: ";
	cin >> size;
	cout << "Enter interval: ";
	cin >> interval;
	try
	{
		if (size <= 0)
		{
			throw "Incorrect number of participants!!!";
		}
		if (interval <= 0)
		{
			throw "Incorrect interval!!!";
		}
	}
	catch (char *error)
	{
		cout << "ERROR: " << error << endl;
		return 0;
	}
	exJoseph(interval, size);
	return 0;
}