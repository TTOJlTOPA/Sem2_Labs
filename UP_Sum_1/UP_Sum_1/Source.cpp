#include <iostream>
#include <string>
using namespace std;

int main()
{
	char cstr[] = "asdf sjgh sdhfng skhdfg sdf sac dkjf sdl glhsdf lkfjf";
	string str, strcomp = "sdf";
	size_t found;
	str = cstr;
	cout << str << endl;
	found = str.find("sdf");
	if (found != str.npos)
	{
		cout << "First 'sdf' found at " << found << endl;
	}
	found = str.rfind("sdf");
	if (found != str.npos)
	{
		cout << "Last 'sdf' found at " << found << endl;
	}
	strcpy(cstr, "");
	found = str.copy(cstr, 4, 5);
	cstr[found] = '\0';
	cout << cstr << endl;
	if (str.compare(strcomp) != 0)
	{
		cout << "str != strcomp" << endl;
	}
	if (str.compare(1, 3, strcomp) == 0)
	{
		cout << "part of str = strcomp" << endl;
	}
	str.replace(10, 7, str.substr(0, 5));
	cout << str << endl;
	str.insert(5, str.substr(0, 5));
	cout << str << endl;
	found = str.find_first_of("g");
	if (found != str.npos)
	{
		str[found] = '*';
	}
	found = str.find_last_of("d");
	if (found != str.npos)
	{
		str[found] = '$';
	}
	cout << str << endl;
	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}