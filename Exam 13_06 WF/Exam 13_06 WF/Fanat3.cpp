#include "Fanat3.h"

Fanat3::Fanat3()
{
	strcpy(Nationality, "");
	strcpy(Name, "");
	Year = 0;
	Code = 0;
	N = 0;
}
Fanat3::Fanat3(char* nation, char* name, int year, int code, int n)
{
	strcpy(Nationality, nation);
	strcpy(Name, name);
	Year = year;
	Code = code;
	N = n;
}
Fanat3::Fanat3(const Fanat3& init)
{
	strcpy(Nationality, init.Nationality);
	strcpy(Name, init.Name);
	Year = init.Year;
	Code = init.Code;
	N = init.N;
}
Fanat3::~Fanat3()
{}
Fanat3& Fanat3::operator = (const Fanat3& right)
{
	if (this != &right)
	{
		strcpy(Nationality, right.Nationality);
		strcpy(Name, right.Name);
		Year = right.Year;
		Code = right.Code;
		N = right.N;
	}
	return *this;
}
istream& operator >> (istream& in, Fanat3& data)
{
	char buf[100];
	in.getline(buf, 100);
	strcpy(data.Nationality, buf);
	in.getline(buf, 100);
	strcpy(data.Name, buf);
	in.getline(buf, 100);
	data.Year = atoi(buf);
	in.getline(buf, 100);
	data.Code = atoi(buf);
	in.getline(buf, 100);
	data.N = atoi(buf);
	return in;
}
ostream& operator << (ostream& out, const Fanat3& data)
{
	out << data.Nationality << "\t" << data.Name << "\t" << data.Year << "\t" << data.Code << "\t" << data.N << "\r\n";
	return out;
}