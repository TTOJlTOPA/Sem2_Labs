#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangles : public Figure
{
public:
	Rectangles();
	Rectangles(int lx, int ly, int rx, int ry);
	Rectangles(const Rectangles& init);
	virtual ~Rectangles();

	int getLXY(int index);
	int getRXY(int index);
	double getPerimeter();
	double getSquare();

	virtual void fPerimeter();
	virtual void fSquare();
	virtual void fMove(int x, int y);
	virtual void fAlteration(int x, int y);
};

#endif