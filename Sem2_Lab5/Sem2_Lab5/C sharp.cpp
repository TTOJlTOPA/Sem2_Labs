#include "C sharp.h"

Cshrp::Cshrp() : Cpp()
{
	name = "C#";
	creator = "Anders Hejlsberg";
	year = 2000;
	gen = "Generalized programming";
	dec = "Declarative";
}
void Cshrp::print()
{
	cout << "Programming language: " << name << "\nCreator: " << creator << "\nYear of appearance : " << year << endl;
	cout << "Paradigm:\n" << oop << "\n" << imp << "\n" << func << "\n" << refl << "\n" << gen << "\n" << distr << "\n" << dec << "\n" << endl;
}