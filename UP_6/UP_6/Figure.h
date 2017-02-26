#ifndef FIGURE_H
#define FIGURE_H
#define PI 3.14159265

#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

class Figure
{
protected:
	char* name;
	int lPoint[2];
	int rPoint[2];
	int side;
	double perim;
	double square;
public:
	virtual void fPerimeter() = 0;
	virtual void fSquare() = 0;
	virtual void fMove(int x, int y) = 0;
	virtual void fAlteration(int x, int y) = 0;
	virtual void fDraw(HDC hdc) = 0;
};

#endif