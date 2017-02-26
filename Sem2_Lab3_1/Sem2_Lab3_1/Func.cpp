#include "Func.h"

int operatorToPriority(char op)
{
	if (op == '(')
	{
		return 0;
	}
	if (op == '+' || op == '-')
	{
		return 1;
	}
	if (op == '*' || op == '/')
	{
		return 2;
	}
	if (op == '^')
	{
		return 3;
	}
}
bool priority(stack <char>& stck, const char symb)
{
	int opst, opcur;
	if (!stck.empty())
	{
		opst = operatorToPriority(stck.top());
		opcur = operatorToPriority(symb);
		if (opst >= opcur)
		{
			return true;
		}
	}
	return false;
}
void exPolishNotation(char* compl)
{
	stack <char> stck;
	char str[100], symb;
	int num, j = 0;
	cout << "Enter expression: ";
	gets(str);
	for (int i = 0; i < strlen(str); i++)
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			compl[j] = str[i];
			i++;
			j++;
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == '(')
		{
			if (str[i] != '(')
			{
				compl[j] = ' ';
				j++;
				while (priority(stck, str[i]))
				{
					compl[j] = stck.top();
					stck.pop();
					j++;
					compl[j] = ' ';
					j++;
				}
			}
			stck.push(str[i]);
		}
		if (str[i] == ')')
		{
			while (!stck.empty() && (symb = stck.top()) != '(')
			{
				stck.pop();
				compl[j] = ' ';
				j++;
				compl[j] = symb;
				j++;
			}
			if (stck.top() == '(')
			{
				stck.pop();
			}
		}
	}
	while (!stck.empty())
	{
		compl[j] = ' ';
		j++;
		compl[j] = stck.top();
		stck.pop();
		j++;
	}
	compl[j] = '\0';
}
double fromSymbToNum(char symb)
{
	double counter = 0;
	for (int i = 48; i <= 57; i++)
	{
		if (symb == i)
		{
			return counter;
		}
		counter++;
	}
	return -1;
}
double calculations(char* str)
{
	stack <double> stck;
	double num, res, tmpnum;
	int i;
	char *word, delim[] = " ";
	word = strtok(str, delim);
	while (word)
	{
		if (word[0] >= '0' && word[0] <= '9')
		{
			i = 0;
			num = 0;
			while (word[i])
			{
				num *= 10;
				num += fromSymbToNum(word[i]);
				i++;
			}
			stck.push(num);
		}
		switch (word[0])
		{
			case '+':
			{
				res = stck.top();
				stck.pop();
				res += stck.top();
				stck.pop();
				stck.push(res);
				break;
			}
			case '-':
			{
				num = stck.top();
				stck.pop();
				res = stck.top();
				stck.pop();
				res -= num;
				stck.push(res);
				break;
			}
			case '*':
			{
				res = stck.top();
				stck.pop();
				res *= stck.top();
				stck.pop();
				stck.push(res);
				break;
			}
			case '/':
			{
				num = stck.top();
				stck.pop();
				res = stck.top();
				stck.pop();
				res /= num;
				stck.push(res);
				break;
			}
			case '^':
			{
				res = 1;
				num = stck.top();
				stck.pop();
				tmpnum = stck.top();
				stck.pop();
				for (int i = 0; i < num; i++)
				{
					res *= tmpnum;
				}
				stck.push(res);
				break;
			}
		}
		word = strtok(NULL, delim);
	}
	res = stck.top();
	stck.pop();
	return res;
}
