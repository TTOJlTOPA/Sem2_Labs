#include "Container3.h"

Container3& Container3::operator = (const Container3& right)
{
	if (this != &right)
	{
		strcpy(Name, right.Name);
		strcpy(Addr, right.Addr);
		Price = right.Price;
	}
	return *this;
}
ostream& operator << (ostream& out, const Container3& elem)
{
	out << elem.Name << "\t" << elem.Addr << "\t" << elem.Price << "\r\n";
	return out;
}
istream& operator >> (istream& in, Container3& elem)
{
	in >> elem.Name >> elem.Addr >> elem.Price;
	return in;
}