#include "Circle.h"

Circle::Circle()
{
	name = new char[strlen("Круг") + 1];
	strcpy(name, "Круг");
	for (int i = 0; i < 2; i++)
	{
		lPoint[i] = 0;
		rPoint[i] = 0;
	}
	side = 1;
}
Circle::Circle(int lx, int ly, int rx, int ry)
{
	name = new char[strlen("Круг") + 1];
	strcpy(name, "Круг");
	lPoint[0] = lx;
	lPoint[1] = ly;
	rPoint[0] = rx;
	rPoint[1] = ry;
	cRadius();
	fPerimeter();
	fSquare();
	side = 1;
}
Circle::Circle(const Circle& init)
{
	name = new char[strlen("Круг") + 1];
	strcpy(name, "Круг");
	for (int i = 0; i < 2; i++)
	{
		lPoint[i] = init.lPoint[i];
		rPoint[i] = init.rPoint[i];
	}
	R = init.R;
	side = 1;
}
Circle::~Circle()
{
	delete[] name;
}
void Circle::cRadius()
{
	R = sqrt((rPoint[0] - lPoint[0])*(rPoint[0] - lPoint[0]) + (rPoint[1] - lPoint[1])*(rPoint[1] - lPoint[1]));
}

int Circle::getLXY(int index)
{
	if (index >= 0 && index <= 1)
	{
		return lPoint[index];
	}
	return 0;
}
int Circle::getRXY(int index)
{
	if (index >= 0 && index <= 1)
	{
		return rPoint[index];
	}
	return 0;
}
double Circle::getPerimeter()
{
	return perim;
}
double Circle::getSquare()
{
	return square;
}
double Circle::getR()
{
	return R;
}

void Circle::fPerimeter()
{
	perim = 2 * PI * R;
}
void Circle::fSquare()
{
	square = PI * R * R;
}
void Circle::fMove(int x, int y)
{
	lPoint[0] += x;
	lPoint[1] += y;
	rPoint[0] += x;
	rPoint[1] += y;
}
void Circle::fAlteration(int x, int y)
{
	rPoint[0] += x;
	rPoint[1] += y;
	fPerimeter();
	fSquare();
	cRadius();
}