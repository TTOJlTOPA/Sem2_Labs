#include "Coding.h"
#include "Pascal.h"
#include "C sharp.h"

int main()
{
	Coding **coding = new Coding*[4];
	coding[0] = new Pascal;
	coding[1] = new C;
	coding[2] = new Cpp;
	coding[3] = new Cshrp;
	for (int i = 0; i < 4; i++)
	{
		coding[i]->print();
	}
	for (int i = 0; i < 4; i++)
	{
		delete coding[i];
	}
	delete[] coding;
	return 0;
}