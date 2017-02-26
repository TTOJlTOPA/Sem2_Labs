#include "stdafx.h"
#include "S2.h"

S2::S2()
{
	
}
S2::S2(char* name)
{
	strcpy(Name, name);
}
S2::S2(const S2& init)
{
	strcpy(Name, init.Name);
}
S2::~S2()
{

}
const S2& S2::operator = (const S2& right)
{
	if (this != &right)
	{
		strcpy(Name, right.Name);
	}
	return *this;
}
ostream& operator << (ostream& out, const S2 obj)
{
	out << obj.Name << "\n";
	return out;
}