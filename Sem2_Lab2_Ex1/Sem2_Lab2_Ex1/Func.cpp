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
bool priority(Stackchar& stack, const char symb)
{
	int opst, opcur;
	if (stack.stackStatus())
	{
		opst = operatorToPriority(stack.getHead());
		opcur = operatorToPriority(symb);
		if (opst >= opcur)
		{
			return true;
		}
	}
	return false;
}
char* exPolishNotation(char *compl)
{
	Stackchar stack;
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
				while (priority(stack, str[i]))
				{
					compl[j] = stack.pop();
					j++;
					compl[j] = ' ';
					j++;
				}
			}
			stack.push(str[i]);
		}
		if (str[i] == ')')
		{
			while (stack.stackStatus() && (symb = stack.pop()) != '(')
			{
				compl[j] = ' ';
				j++;
				compl[j] = symb;
				j++;
			}
		}
	}
	while (stack.stackStatus())
	{
		compl[j] = ' ';
		j++;
		compl[j] = stack.pop();
		j++;
	}
	compl[j] = '\0';
	return compl;
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
double calculations(char *str)
{
	Stackdouble stack;
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
			stack.push(num);
		}
		switch (word[0])
		{
			case '+':
			{
				res = stack.pop();
				res += stack.pop();
				stack.push(res);
				break;
			}
			case '-':
			{
				num = stack.pop();
				res = stack.pop();
				res -= num;
				stack.push(res);
				break;
			}
			case '*':
			{
				res = stack.pop();
				res *= stack.pop();
				stack.push(res);
				break;
			}
			case '/':
			{
				num = stack.pop();
				res = stack.pop();
				res /= num;
				stack.push(res);
				break;
			}
			case '^':
			{
				res = 1;
				num = stack.pop();
				tmpnum = stack.pop();
				for (int i = 0; i < num; i++)
				{
					res *= tmpnum;
				}
				stack.push(res);
				break;
			}
		}
		word = strtok(NULL, delim);
	}
	res = stack.pop();
	return res;
}