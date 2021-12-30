#include "Point.h"

Point::Point(int x, int y): x{x}, y{y}
{
}

Point::Point(): x{0}, y{0}
{
}

int Point::X() const 
{
	return this->x;
}

int Point::Y() const 
{
	return this->y;
}

void Point::setX(int x) 
{
	this->x=x;
}

void Point::setY(int y) 
{
	this->y = y;
}

double Point::Distance(Point& p) 
{
	
	return sqrt((this->x - p.X()) * (this->x - p.X()) + (this->y - p.Y()) * (this->y - p.Y()));
}