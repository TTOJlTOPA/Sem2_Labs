#include "Human.h"

Human::Human()
{
	strcpy(name, "");
	age = 0;
	weight = 0;
}
Human::Human(char* iname, int iage, int iweight)
{
	strcpy(name, iname);
	age = iage;
	weight = iweight;
}
Human::Human(const Human& init)
{
	strcpy(name, init.name);
	age = init.age;
	weight = init.weight;
}
Human::~Human()
{

}
void Human::Print(ostream& out)
{
	out << name << "\t\t" << age << "\t" << weight << "\r\n";
}