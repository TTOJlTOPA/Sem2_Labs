#include "Container2.h"

Container2& Container2::operator = (const Container2& right)
{
	if (this != &right)
	{
		strcpy(Name, right.Name);
		data = right.data;
	}
	return *this;
}
ostream& operator << (ostream& out, const Container2& elem)
{
	out << elem.Name << "\t" << elem.data << "\r\n";
	return out;
}
istream& operator >> (istream& in, Container2& elem)
{
	in >> elem.Name >> elem.data;
	return in;
}