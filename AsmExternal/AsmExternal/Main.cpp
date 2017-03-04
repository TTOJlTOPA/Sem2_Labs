// Ќайти N пар взаимно-простых натуральных чисел.
#include <iostream>
using namespace std;
extern	"C" void _cdecl func1(int, int*);
extern  "C" void _fastcall func2(int, int*);
extern  "C" void _stdcall func3(int, int*);

int main()
{
	int size, *arr;
	cout << "Enter the number of pairs: ";
	cin >> size;
	arr = new int[size + 1];
	func3(size, arr);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t" << arr[i + 1] << endl;
	}
	delete[] arr;
	return 0;
}