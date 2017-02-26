#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

void print(vector<int>& vec)
{
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> a, b, res;
	vector<int>::iterator iter, iterat;
	ostream_iterator<int> outit(cout, " ");
	for (int i = 0; i < 10; i++)
	{
		a.push_back(rand() % 10);
		b.push_back(rand() % 10);
	}
	cout << "a: ";
	print(a);
	cout << "b: ";
	print(b);
	iter = a.begin();
	iter = a.insert(iter, 20);
	iter = a.insert(iter + 5, 30);
	cout << "a: ";
	print(a);
	iter = a.begin();
	a.erase(iter);
	iter = a.begin();
	a.erase(iter + 4);
	cout << "a: ";
	print(a);
	iter = a.begin();
	*iter = 20;
	cout << "a: ";
	print(a);
	sort(a.begin(), a.end());
	cout << "Sorted a: ";
	print(a);
	iter = b.begin();
	sort(iter, iter + 5);
	cout << "Partially sorted b: ";
	print(b);
	iter = a.begin();
	if (binary_search(a.begin(), a.end(), 4))
	{
		cout << "There is 4 in a!\n";
	}
	else
	{
		cout << "There is no 4 in a!\n";
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	iter = find_first_of(a.begin(), a.end(), b.begin(), b.begin() + 5);
	if (iter != a.end())
	{
		cout << "Vector b don't found in a!" << endl;
	}
	else
	{
		cout << "Vector b found in a!" << endl;
	}
	copy(a.begin(), a.end(), b.begin());
	cout << "b: ";
	print(b);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	res.resize(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());
	cout << "res: ";
	print(res);
	cout << "Sum of res's elements: " << accumulate(a.begin(), a.end(), 0) << endl;
	cout << "size of a: " << a.size() << "\nmax size of a: " << a.max_size() << endl;
	cout << "a: ";
	copy(a.begin(), a.end(), outit);
	cout << endl;
	return 0;
}