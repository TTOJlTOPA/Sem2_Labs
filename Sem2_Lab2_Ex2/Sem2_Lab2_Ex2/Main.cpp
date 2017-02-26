#include "Queue.h"

void main()
{
	Queue primeQ, palinQ, thirdQ;
	fInput(primeQ, palinQ);
	cout << "\n\t\t\t\t Queue primeQ" << endl;
	primeQ.showQueue();
	cout << "\n\t\t\t\t Queue palinQ" << endl;
	palinQ.showQueue();
	thirdQForm(thirdQ, primeQ, palinQ);
	cout << "\n\t\t\t\t Queue thirdQ" << endl;
	thirdQ.showQueue();
	fOutput(thirdQ);
}