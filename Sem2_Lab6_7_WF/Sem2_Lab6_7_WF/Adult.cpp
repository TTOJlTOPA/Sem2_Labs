#include "Adult.h"

Adult::Adult() : Human()
{
	passport = 0;
}
Adult::Adult(char* iname, int iage, int iweight, int ipassport) : Human(iname, iage, iweight)
{
	passport = ipassport;
}
Adult::Adult(const Adult& init) : Human(init)
{
	passport = init.passport;
}
Adult::~Adult()
{}
void Adult::Print(ostream& out)
{
	out << name << "\t\t" << age << "\t" << weight << "\t" << passport << "\r\n";
}
void Adult::setAge(const int newage)
{
	age = newage;
}
void Adult::setPassport(const int newpassport)
{
	passport = newpassport;
}