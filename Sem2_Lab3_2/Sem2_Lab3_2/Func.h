#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

bool inputFileCheck(ifstream&);
bool outputFileCheck(ofstream&);
bool primeCheck(const int);
bool palindromeCheck(const int);
void fInput(queue <int>&, queue <int>&, ifstream&);
void thirdQForm(queue <int>&, queue <int>&, queue <int>&);
void fOutput(queue <int>&, ofstream&);

#endif