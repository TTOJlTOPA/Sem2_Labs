#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <stack>
using namespace std;

int operatorToPriority(char);
bool priority(const stack <char>&, const char);
void exPolishNotation(char*);
double fromSymbToNum(char);
double calculations(char*);

#endif