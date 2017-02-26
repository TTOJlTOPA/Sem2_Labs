#ifndef S2_H
#define S2_H

#include <iostream>
using namespace std;

struct S2
{
	char Name[50];
	S2();
	S2(char *name);
	S2(const S2& init);
	~S2();
	const S2& operator = (const S2& right);
	friend ostream& operator << (ostream& out, const S2 obj);
};

#endif