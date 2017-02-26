#include "List.h"

void main()
{
	int n, m;
	List a;
	char name[20];
	cout << "Enter number of participants: ";
	cin >> n;
	cin.clear();
	while (cin.get() != '\n');
	for (int i = 0; i < n; i++)
	{
		cout << "Enter name of participant " << i + 1 << ": ";
		gets(name);
		a.push(name);
	}
	cout << "Enter intelval: ";
	cin >> m;
	cout << "\n\t\t\t\t THE GAME BEGINS!!!\n" << endl;
	a.exJoseph(m, n);
}