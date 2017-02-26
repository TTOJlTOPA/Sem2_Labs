#include "S3.h"

S3::S3()
{
	Price = 0;
	strcpy(ControlDate, "21 θώνÿ 2007γ");
}
S3::S3(char* name, double price)
{
	strcpy(Name, name);
	strcpy(ControlDate, "21 θώνÿ 2007γ");
	Price = price;
}
S3::S3(const S3& init)
{
	strcpy(Name, init.Name);
	strcpy(ControlDate, init.ControlDate);
	Price = init.Price;
}
S3::~S3()
{

}
const S3& S3::operator = (const S3& right)
{
	if (this != &right)
	{
		strcpy(Name, right.Name);
		Price = right.Price;
		strcpy(ControlDate, right.ControlDate);
	}
	return *this;
}
ostream& operator << (ostream& out, const S3 obj)
{
	out << obj.Name << "\t" << obj.Price << "\t" << obj.ControlDate << "\n";
	return out;
}