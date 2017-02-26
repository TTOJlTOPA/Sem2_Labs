#include "Func.h"

bool inputFileCheck(ifstream& fin)
{
	int num;
	try
	{
		if (!fin)
		{
			throw "Input file not found!";
		}
		if (!(fin >> num))
		{
			throw "Input file is empty!";
		}
	}
	catch (char *error)
	{
		cout << error << endl;
		return false;
	}
	fin.clear();
	fin.seekg(0, ios::beg);
	return true;
}
bool outputFileCheck(ofstream& fout)
{
	try
	{
		if (!fout)
		{
			throw "Output file not found!";
		}
	}
	catch (char *error)
	{
		cout << error << endl;
		return false;
	}
	return true;
}
bool primeCheck(const int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}
bool palindromeCheck(const int num)
{
	int tmpnum = num, tmpcheck = 0;
	if (num / 10 == 0)
	{
		return true;
	}
	while (tmpnum != 0)
	{
		tmpcheck *= 10;
		tmpcheck += tmpnum % 10;
		tmpnum /= 10;
	}
	if (num != tmpcheck)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void fInput(queue <int>& primeQ, queue <int>& palinQ, ifstream& fin)
{
	int num;
	cout << "\t\t\t\t Input file:" << endl;
	while (fin >> num)
	{
		cout << num << endl;
		if (primeCheck(num))
		{
			primeQ.push(num);
		}
		if (palindromeCheck(num))
		{
			palinQ.push(num);
		}
	}
	fin.close();
}
void thirdQForm(queue <int>& thirdQ, queue <int>& primeQ, queue <int>& palinQ)
{
	int num;
	while (!primeQ.empty())
	{
		num = primeQ.front();
		primeQ.pop();
		//if (thirdQ.repeatCheck(num))
		//{
			thirdQ.push(num);
		//}
	}
	while (!palinQ.empty())
	{
		num = palinQ.front();
		palinQ.pop();
		//if (thirdQ.repeatCheck(num))
		//{
			thirdQ.push(num);
		//}
	}
}
void fOutput(queue <int>& thirdQ, ofstream& fout)
{
	int num;
	cout << "\t\t\t\t Output file:" << endl;
	while (!thirdQ.empty())
	{
		num = thirdQ.front();
		thirdQ.pop();
		fout << num << "\n";
		cout << num << endl;
	}
	fout.close();
}