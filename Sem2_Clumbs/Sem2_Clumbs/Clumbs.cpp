#include "Clumbs.h"

vector<Clumbs> input(ifstream& fin)
{
	char *word;
	int counter = 0;
	if (!fin.is_open())
	{
		throw "File doesn't exist!";
	}
	char s[100];
	if (!fin.getline(s, 100))
	{
		throw "File is empty!";
	}
	fin.clear();
	fin.seekg(0, ios::beg);
	while (fin.getline(s, 100))
	{
		counter++;
	}
	fin.clear();
	fin.seekg(0, ios::beg);
	vector<Clumbs> data(counter);
	for (int i = 0; i < counter; i++)
	{
		fin.getline(s, 100);
		word = strtok(s, "; ,");
		data[i].num = atoi(word);
		word = strtok(NULL, "; ,");
		data[i].form = string(word);
		word = strtok(NULL, "; ,");
		while (word)
		{
			data[i].flow.push_back(string(word));
			word = strtok(NULL, "; ,");
		}
	}
	return data;
}
void Sort(vector<Clumbs>& data)
{
	comp compare;
	set<string> flow;
	sort(data.begin(), data.end(), compare);
	for (auto i = data.begin(); i != data.end(); i++)
	{
		for (auto j = i->flow.begin(); j != i->flow.end(); j++)
		{
			flow.insert(*j);
		}
	}
	cout << "Flowers on clumbs: " << endl;
	for (auto i = flow.begin(); i != flow.end(); i++)
	{
		cout << *i << ' ';
	}
	cout << endl;
}
void Search(vector<Clumbs>& data)
{
	string str;
	bool flag;
	cout << "\nEnter searching flower: ";
	cin >> str;
	cout << endl;
	for (auto i = data.begin(); i != data.end(); i++)
	{
		flag = false;
		for (auto j = i->flow.begin(); j != i->flow.end(); j++)
		{
			if (*j == str)
			{
				flag = true;
			}
		}
		if (!flag)
		{
			cout << "Number: " << i->num << "; Form: " << i->form << "; Flow: ";
			for (auto j = i->flow.begin(); j != i->flow.end(); j++)
			{
				cout << *j << ' ';
			}
			cout << endl;
		}
	}
}
void Everywhere(vector<Clumbs>& data)
{
	map<string, int> flow1;
	int flag = 0;
	cout << endl << "Flow on every clumb: " << endl;
	for (auto i = data.begin(); i != data.end(); i++)
	{
		set<string> temp;
		for (auto j = i->flow.begin(); j != i->flow.end(); j++)
		{
			temp.insert(*j);
		}
		for (auto j = temp.begin(); j != temp.end(); j++)
		{
			flow1[*j]++;
			if (flow1[*j] == data.size())
			{
				cout << *j << endl;
				flag = 1;
			}
		}
	}
	cout << endl;
	if (!flag)
	{
		cout << "No flow, that on every clumb!" << endl;
	}
}
void SearchNum(vector<Clumbs>& data)
{
	int num, ans = 0;
	list<string> temp;
	cout << "Enter number of flow: ";
	cin >> num;
	for (auto i = data.begin(); i != data.end(); i++)
	{
		temp = i->flow;
		unique(temp.begin(), temp.end());
		if (temp.size() == num)
		{
			ans++;
		}
	}
	cout << ans << endl;
}
void Change(vector<Clumbs>& data)
{
	string oldflow, newflow;
	cout << "Enter old flower: ";
	cin >> oldflow;
	cout << "Enter new flower: ";
	cin >> newflow;
	for (auto i = data.begin(); i != data.end(); i++)
	{
		replace(i->flow.begin(), i->flow.end(), oldflow, newflow);
	}
	for (auto i = data.begin(); i != data.end(); i++)
	{
		cout << "Number: " << i->num << "; Form: " << i->form << "; Flow: ";
		for (auto j = i->flow.begin(); j != i->flow.end(); j++)
		{
			cout << *j << ' ';
		}
		cout << endl;
	}
}