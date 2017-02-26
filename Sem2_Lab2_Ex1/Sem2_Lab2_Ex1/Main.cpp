#include "Func.h"

int main()
{
	char compl[200];
	exPolishNotation(compl);
	cout << "Polish notation: ";
	puts(compl);
	cout << "Result of calculations: " << calculations(compl) << endl;
	return 0;
}