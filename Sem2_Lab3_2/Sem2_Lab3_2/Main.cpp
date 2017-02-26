#include "Func.h"

int main()
{
	queue <int> primeQ, palinQ, thirdQ;
	ifstream fin("Input.txt");
	ofstream fout("Output.txt");
	if (!inputFileCheck(fin) && !outputFileCheck(fout))
	{
		return 0;
	}
	fInput(primeQ, palinQ, fin);
	thirdQForm(thirdQ, primeQ, palinQ);
	fOutput(thirdQ, fout);
	return 1;
}