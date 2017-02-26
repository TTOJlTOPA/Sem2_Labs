#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"

class Circle : public Figure
{
	double R;
public:
	Circle();
	Circle(int lx, int ly, int rx, int ry);
	Circle(const Circle& init);
	virtual ~Circle();
	void cRadius();

	int getLXY(int index);
	int getRXY(int index);
	double getPerimeter();
	double getSquare();
	double getR();

	virtual void fPerimeter();
	virtual void fSquare();
	virtual void fMove(int x, int y);
	virtual void fAlteration(int x, int y);
};

#endif