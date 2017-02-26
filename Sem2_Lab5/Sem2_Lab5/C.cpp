#include "C.h"

C::C()
{
	name = "C";
	creator = "Dennis Ritchie";
	year = 1973;
	oop = "Object-oriented(partially)";
	imp = "Imperative";
	func = "Functional(partially)";
	gen = "Generalized programming";
	distr = "Distributed";
}
void C::print()
{
	cout << "Programming language: " << name << "\nCreator: " << creator << "\nYear of appearance : " << year << endl;
	cout << "Paradigm:\n" << oop << "\n" << imp << "\n" << func << "\n" << gen << "\n" << distr << "\n" << endl;
}