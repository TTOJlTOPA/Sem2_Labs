#include "S1.h"

S1::S1()
{
	Price = 0;
}
S1::S1(char *name, double price)
{
	strcpy(Name, name);
	Price = price;
}
S1::S1(const S1& init)
{
	strcpy(Name, init.Name);
	Price = init.Price;
}
S1::~S1()
{

}
const S1& S1::operator = (const S1& right)
{
	if (this != &right)
	{
		strcpy(Name, right.Name);
		Price = right.Price;
	}
	return *this;
}
ostream& operator << (ostream& out, const S1 obj)
{
	out << obj.Name << "\t" << obj.Price << "\n";
	return out;
}