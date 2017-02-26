#include "Func.h"

int main()
{
	int size, interval;
	cout << "Enter number of participants: ";
	cin >> size;
	cin.clear();
	while (cin.get() != '\n');
	try
	{
		if (size <= 0)
		{
			throw "There is no participants!";
		}
	}
	catch (char *error)
	{
		cout << error << endl;
		return 0;
	}
	cout << "Enter intelval: ";
	cin >> interval;
	cout << "\n\t\t\t\t THE GAME BEGINS!!!\n" << endl;
	exJoseph(interval, size);
	return 1;
}