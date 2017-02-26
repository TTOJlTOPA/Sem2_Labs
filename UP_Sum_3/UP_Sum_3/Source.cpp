#include <iostream>
#include "Deque.h"
#include <deque>
using namespace std;

int main()
{
	Deque<int> deqint(10);
	Deque<double> deqdouble(10);
	Deque<char> deqchar(10);
	int tmp;
	cout << "Int: ";
	deqint.print(cout);
	cout << "Double: ";
	deqdouble.print(cout);
	cout << "Char: ";
	deqchar.print(cout);
	tmp = rand() % 100;
	cout << "Add " << tmp << " to the front of decint." << endl;
	deqint.push_front(tmp);
	tmp = rand() % 100;
	cout << "Add " << tmp << " to the back of decint." << endl;
	deqint.push_back(tmp);
	cout << "Changed decint: ";
	deqint.print(cout);
	cout << "Sum of decint: " << deqint.sum() << endl;
}