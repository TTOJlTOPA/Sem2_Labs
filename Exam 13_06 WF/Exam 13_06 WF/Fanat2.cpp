#include "Fanat2.h"

Fanat2::Fanat2()
{
	strcpy(Name, "");
	Code = 0;
	N = 0;
}
Fanat2::Fanat2(char* name, int code, int n)
{
	strcpy(Name, name);
	Code = code;
	N = n;
}
Fanat2::Fanat2(const Fanat2& init)
{
	strcpy(Name, init.Name);
	Code = init.Code;
	N = init.N;
}
Fanat2::~Fanat2()
{}
Fanat2& Fanat2::operator = (const Fanat2& right)
{
	if (this != &right)
	{
		strcpy(Name, right.Name);
		Code = right.Code;
		N = right.N;
	}
	return *this;
}
istream& operator >> (istream& in, Fanat2& data)
{
	char buf[100];
	in.getline(buf, 100);
	strcpy(data.Name, buf);
	in.getline(buf, 100);
	data.Code = atoi(buf);
	in.getline(buf, 100);
	data.N = atoi(buf);
	return in;
}
ostream& operator << (ostream& out, const Fanat2& data)
{
	out << data.Name << "\t" << data.Code << "\t" << data.N << "\r\n";
	return out;
}