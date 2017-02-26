#ifndef S3_H
#define S3_H

#include <iostream>
using namespace std;

struct S3
{
	char Name[50];
	char ControlDate[25];
	double Price;
	S3();
	S3(char* name, double price);
	S3(const S3& init);
	~S3();
	const S3& operator = (const S3& right);
	friend ostream& operator << (ostream& out, const S3 obj);
};

#endif