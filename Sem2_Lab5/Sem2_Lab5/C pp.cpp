#include "C pp.h"

Cpp::Cpp() : C()
{
	name = "C++";
	creator = "Bjarne Stroustrup";
	year = 1983;
	oop = "Object-oriented";
	refl = "Refexive";
	gen = "Generalized programming(partially)";
}
void Cpp::print()
{
	cout << "Programming language: " << name << "\nCreator: " << creator << "\nYear of appearance : " << year << endl;
	cout << "Paradigm:\n" << oop << "\n" << imp << "\n" << func << "\n" << refl << "\n" << gen << "\n" << distr << "\n" << endl;
}