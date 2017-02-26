#ifndef CLUMBS_H
#define CLUMBS_H
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;
class Clumbs
{
	int num;
	string form;
	list<string> flow;
public:
	friend class comp;
	friend vector<Clumbs> input(ifstream& fin);
	friend void Sort(vector<Clumbs>& data);
	friend void Search(vector<Clumbs>& data);
	friend void Everywhere(vector<Clumbs>& data);
	friend void SearchNum(vector<Clumbs>& data);
	friend void Change(vector<Clumbs>& data);
};
class comp
{
public:
	bool operator()(Clumbs& a, Clumbs& b)
	{
		if (a.form == b.form)
			return a.num < b.num;
		else return a.form < b.form;
	}
};
#endif CLUMBS_H