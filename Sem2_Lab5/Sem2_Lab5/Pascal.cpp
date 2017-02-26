#include "Pascal.h"

Pascal::Pascal()
{
	name = "Pascal";
	creator = "Niklaus Wirth";
	year = 1970;
}
void Pascal::print()
{
	cout << "Programming language: " << name << "\nCreator: " << creator << "\nYear of appearance : " << year << "\n\n" << endl;
}