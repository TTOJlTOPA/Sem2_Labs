#include "Queue.h"

Queue::Link::Link(const int dat, Link* nxt)
{
	data = dat;
	next = 0;
}
Queue::Link::Link(const Link& copy, Link* nxt)
{
	data = copy.data;
	next = nxt;
}
Queue::Link::~Link()
{} //!!!!!!!!!!!!!!!!!!!
Queue::Queue()
{
	rear = 0;
	front = 0;
}
Queue::~Queue()
{} //??????
void Queue::push(const int dat)
{
	Link *tmp = new Link(dat, rear);
	if (rear != 0)
	{
		rear->next = tmp;
	}
	rear = tmp;
	if (front == 0)
	{
		front = rear;
	}
}
int Queue::pop()
{
	int dat;
	if (front != 0)
	{
		Link *tmp = front;
		dat = tmp->data;
		if (front->next != 0)
		{
			front = front->next;
		}
		else
		{
			front = 0;
			rear = 0;
		}
		delete tmp;
		return dat;
	}
	else
	{
		return 0;
	}
}
void Queue::showQueue()
{
	Link *tmp = front;
	while (tmp != 0)
	{
		cout << tmp->data << endl;
		tmp = tmp->next;
	}
}
bool Queue::repeatCheck(const int num)
{
	Link *tmp = front;
	while (tmp != 0)
	{
		if (tmp->data == num)
		{
			return false;
		}
		tmp = tmp->next;
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
		return false;
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
void fInput(Queue& primeQ, Queue& palinQ)
{
	ifstream fin("Input.txt");
	int num;
	try
	{
		if (!fin)
		{
			throw "File not found!";
		}
		if (!(fin >> num))
		{
			throw "Input file is empty!";
		}
	}
	catch (char *error)
	{
		cout << error << endl;
	}
	fin.clear();
	fin.seekg(0, ios::beg);
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
void thirdQForm(Queue& thirdQ, Queue& primeQ, Queue& palinQ)
{
	int num;
	while (num = primeQ.pop())
	{
		if (thirdQ.repeatCheck(num))
		{
			thirdQ.push(num);
		}
	}
	while (num = palinQ.pop())
	{
		if (thirdQ.repeatCheck(num))
		{
			thirdQ.push(num);
		}
	}
}
void fOutput(Queue& thirdQ)
{
	ofstream fout("Output.txt");
	int num;
	try
	{
		if (!fout)
		{
			throw "File not found!";
		}
	}
	catch (char *error)
	{
		cout << error << endl;
	}
	while (num = thirdQ.pop())
	{
		fout << num << "\n";
	}
	fout.close();
}