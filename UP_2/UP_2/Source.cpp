/*Задан текстовый файл Input.txt, состоящий  из слов и некоторое предложение. Разделителями между словами является некоторое множество знаков препинания.
Найти  строки, в которых встречается данное предложение, продублировать первое и последнее слова предложений. Результат записать  в новый файл Output.txt.
Упорядочить слова  в искомых предложениях по  убыванию длин слов, результат сортировки записать в файл Out_sort.txt.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <fstream>
using namespace std;
bool fileCheck(ifstream &fin);

int asmstrlen(char* str)
{
	int len = 0;
	_asm
	{
		lea edx, [str]
		lea eax, [edx - 1]
		xor ecx, ecx
	loop1 :
		inc eax
		cmp cl, [eax]
		jnz loop1
		sub eax, edx
		mov len, eax
	}
	return len;
}

char* asmstrcpy(char* dest, char* res)
{
	int len = asmstrlen(res);
	_asm 
	{
		mov ax, ds
		mov es, ax
		mov esi, res
		mov edi, dest
	A1 : 
		mov ax, [esi]
		mov[edi], ax
		add esi, 1
		add edi, 1
		cmp[esi], 0
		jne A1
	}
	dest[asmstrlen(res)] = '\0';
	return dest;
}

void counter(char *acop, char *tmp2, char *delim, char *tok2, int &count1)
{
	while (tmp2)
	{
		count1++;
		tmp2 = strtok_s(NULL, delim, &tok2);
	}
}
void tmpForm(char *tmpfword, char *tmps, char *tmp1, char *tmplword, char *tmp2, int count1, int &count2)
{
	count2++;
	if (count2 == 1)
	{
		asmstrcpy(tmpfword, tmp2);
	}
	strcat(tmps, tmp1);
	strcat(tmps, " ");
	if (count2 == count1)
	{
		asmstrcpy(tmplword, tmp2);
	}
}
void strForm(char *tmpstr, char *tmpfword, char *tmplword, char *tmps, char *tmp1, int count1, int count2, bool &flag, bool &flag1)
{
	if (count2 == count1)
	{
		flag = true;
		flag1 = true;
		strcat(tmpstr, tmpfword);
		strcat(tmpstr, " ");
		strcat(tmpstr, tmps);
		strcat(tmpstr, tmplword);
		strcat(tmpstr, " ");
		if (tmp1 != 0)
		{
			strcat(tmpstr, tmp1);
			strcat(tmpstr, " ");
		}
	}
	else
	{
		strcat(tmpstr, tmps);
	}
}
void output(char *a, char *delim)
{
	char str[1000] = "", tmpstr[1200] = "", acop[100], tmps[200] = "", *tmp1, *tmp2, *tok1 = NULL, *tok2 = NULL, tmpfword[100] = "", tmplword[100] = "";
	int count1 = 0, count2;
	bool flag, flag1 = false;
	ifstream fin("Input.txt");
	ofstream fout("Output.txt");
	strcpy_s(acop, a);
	tmp2 = strtok_s(acop, delim, &tok2);
	counter(acop, tmp2, delim, tok2, count1);
	strcpy_s(acop, a);
	if (!fileCheck(fin))
	{
		goto end1;
	}
	cout << "Файл Output.txt" << endl;
	fin.clear();
	fin.seekg(0);
	while (fin)
	{
		flag = false;
		fin.getline(str, 1000);
		tmp1 = strtok_s(str, delim, &tok1);
		while (tmp1)
		{
			tmp2 = strtok_s(acop, delim, &tok2);
			count2 = 0;
			if (tmp2 != 0 && strcmp(tmp1, tmp2) == 0)
			{
				while (tmp1 != 0 && tmp2 != 0)
				{
					if (strcmp(tmp1, tmp2) == 0)
					{
						tmpForm(tmpfword, tmps, tmp1, tmplword, tmp2, count1, count2);
					}
					else
					{
						break;
					}
					tmp1 = strtok_s(NULL, delim, &tok1);
					tmp2 = strtok_s(NULL, delim, &tok2);
				}
				strForm(tmpstr, tmpfword, tmplword, tmps, tmp1, count1, count2, flag, flag1);
				asmstrcpy(tmps, "");
			}
			else
			{
				strcat(tmpstr, tmp1);
				strcat(tmpstr, " ");
			}
			asmstrcpy(acop, a);
			tmp1 = strtok_s(NULL, delim, &tok1);
		}
		if (flag)
		{
			fout << tmpstr << "\n";
			cout << tmpstr << endl;
		}
		strcpy(tmpstr, "");
	}
	if (flag1 == false)
	{
		cout << "В данном файле нет искомого предложения!" << endl;
	}
	cout << endl;
end1:
	fin.close();
	fout.close();
}
void strSort(int *arrlen, char **arrw, int i)
{
	for (int a = 0; a <= i - 1; a++)
	{
		for (int b = 0; b <= (i - 1 - a); b++)
		{
			if (arrlen[b + 1] > arrlen[b])
			{
				swap(arrlen[b + 1], arrlen[b]);
				swap(arrw[b + 1], arrw[b]);
			}
		}
	}
}
void sortCounter(char *str, char *delim, int *arrlen, char **arrw, char *word, int &i)
{
	while (word)
	{
		arrlen[i] = asmstrlen(word);
		arrw[i] = word;
		word = strtok(NULL, delim);
		i++;
	}
}
void out_sort(char *delim)
{
	char str[1200] = { 0 }, nstr[1200] = { 0 }, *word;
	char *arrw[100] = { 0 };
	int arrlen[100] = { 0 }, i;
	ifstream finop("Output.txt");
	ofstream fouts("Out_sort.txt");
	if (!fileCheck(finop))
	{
		goto end2;
	}
	cout << "Файл Out_sort.txt" << endl;
	finop.clear();
	finop.seekg(0);
	while (finop)
	{
		i = 0;
		finop.getline(str, 1200);
		word = strtok(str, delim);
		sortCounter(str, delim, arrlen, arrw, word, i);
		strSort(arrlen, arrw, i);
		for (int a = 0; a <= i - 1; a++)
		{
			strcat(nstr, arrw[a]);
			strcat(nstr, " ");
		}
		fouts << nstr << "\n";
		cout << nstr;
		strcpy(nstr, "");
		cout << endl;
	}
end2:
	finop.close();
	fouts.close();
}
void main()
{
	setlocale(LC_ALL, "rus");
	char a[100], delim[] = " ,./;:'[{}]()-_=+!@#$%^&*|\`~";
	cout << "Введите предложение: ";
	gets_s(a);
	output(a, delim);
	out_sort(delim);
}

bool fileCheck(ifstream &f)
{
	if (!f.is_open())
	{
		cout << "Файл не может быть открыт!" << endl;
		f.close();
		return false;
	}
	else
	{
		if (f.eof())
		{
			cout << "Входной файл пуст!" << endl;
			f.close();
			return false;
		}
		else
		{
			return true;
		}
	}
}