#include "point.h"

Point::Point() : _x{ 0.0 }, _y{ 0.0 }
{}

Point::Point(double x, double y) : _x{ x }, _y{ y }
{}

Point::Point(int x, int y) : _x{ static_cast<double>(x) }, _y{ static_cast<double>(y) }
{}

Point::~Point()
{}

double Point::getX() const
{
    return _x;
}

double Point::getY() const
{
    return _y;
}

void Point::setX(double x)
{
    _x = x;
}

void Point::setY(double y)
{
    _y = y;
}

void Point::moveTo(double x, double y)
{
    _x = x;
    _y = y;
}

void Point::moveOf(double dx, double dy)
{
    _x += dx;
    _y += dy;
}
