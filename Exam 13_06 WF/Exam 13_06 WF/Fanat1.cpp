#include "Fanat1.h"

Fanat1::Fanat1()
{
	strcpy(Name, "");
	strcpy(Nationality, "");
	Year = 0;
	N = 0;
}
Fanat1::Fanat1(char* name, char* nation, int year, int n)
{
	strcpy(Name, name);
	strcpy(Nationality, nation);
	Year = year;
	N = n;
}
Fanat1::Fanat1(const Fanat1& init)
{
	strcpy(Name, init.Name);
	strcpy(Nationality, init.Nationality);
	Year = init.Year;
	N = init.N;
}
Fanat1::~Fanat1()
{}
Fanat1& Fanat1::operator = (const Fanat1& right)
{
	if (this != &right)
	{
		strcpy(Name, right.Name);
		strcpy(Nationality, right.Nationality);
		Year = right.Year;
		N = right.N;
	}
	return *this;
}
istream& operator >> (istream& in, Fanat1& data)
{
	char buf[100];
	in.getline(buf, 100);
	strcpy(data.Name, buf);
	in.getline(buf, 100);
	strcpy(data.Nationality, buf);
	in.getline(buf, 100);
	data.Year = atoi(buf);
	in.getline(buf, 100);
	data.N = atoi(buf);
	return in;
}
ostream& operator << (ostream& out, const Fanat1& data)
{
	out << data.Name << "\t" << data.Nationality << "\t" << data.Year << "\t" << data.N << "\r\n";
	return out;
}