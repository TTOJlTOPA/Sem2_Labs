#include "Container1.h"

Container1& Container1::operator = (const Container1& right)
{
	if (this != &right)
	{
		strcpy(Name, right.Name);
		strcpy(Addr, right.Addr);
	}
	return *this;
}
ostream& operator << (ostream& out, const Container1& elem)
{
	out << elem.Name << "\t" << elem.Addr << "\r\n";
	return out;
}
istream& operator >> (istream& in, Container1& elem)
{
	in >> elem.Name >> elem.Addr;
	return in;
}