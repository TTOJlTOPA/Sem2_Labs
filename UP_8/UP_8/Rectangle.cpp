#include "stdafx.h"
#include "Rectangle.h"

Rectangles::Rectangles()
{
	name = new char[strlen("Прямоугольник") + 1];
	strcpy(name, "Прямоугольник");
	for (int i = 0; i < 2; i++)
	{
		lPoint[i] = 0;
		rPoint[i] = 0;
	}
	side = 4;
}
Rectangles::Rectangles(int lx, int ly, int rx, int ry)
{
	name = new char[strlen("Прямоугольник") + 1];
	strcpy(name, "Прямоугольник");
	lPoint[0] = lx;
	lPoint[1] = ly;
	rPoint[0] = rx;
	rPoint[1] = ry;
	fPerimeter();
	fSquare();
	side = 4;
}
Rectangles::Rectangles(const Rectangles& init)
{
	name = new char[strlen("Прямоугольник") + 1];
	strcpy(name, "Прямоугольник");
	for (int i = 0; i < 2; i++)
	{
		lPoint[i] = init.lPoint[i];
		rPoint[i] = init.rPoint[i];
	}
	fPerimeter();
	fSquare();
	side = init.side;
}
Rectangles::~Rectangles()
{
	delete[] name;
}

int Rectangles::getLXY(int index)
{
	if (index >= 0 && index <= 1)
	{
		return lPoint[index];
	}
	return 0;
}
int Rectangles::getRXY(int index)
{
	if (index >= 0 && index <= 1)
	{
		return rPoint[index];
	}
	return 0;
}
double Rectangles::getPerimeter()
{
	return perim;
}
double Rectangles::getSquare()
{
	return square;
}

void Rectangles::fPerimeter()
{
	perim = 2 * ((rPoint[0] - lPoint[0]) + (rPoint[1] - lPoint[1]));
}
void Rectangles::fSquare()
{
	square = (rPoint[0] - lPoint[0]) * (rPoint[1] - lPoint[1]);
}
void Rectangles::fMove(int x, int y)
{
	lPoint[0] += x;
	lPoint[1] += y;
	rPoint[0] += x;
	rPoint[1] += y;
}
void Rectangles::fAlteration(int x, int y)
{
	rPoint[0] += x;
	rPoint[1] += y;
	fPerimeter();
	fSquare();
}