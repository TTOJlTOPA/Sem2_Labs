#ifndef FUNC_H
#define FUNC_H

#include "Stackchar.h"
#include "Stackdouble.h"

int operatorToPriority(char);
bool priority(Stackchar&, const char);
char* exPolishNotation(char*);
double fromSymbToNum(char);
double calculations(char*);

#endif