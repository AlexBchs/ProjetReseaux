#include "hexaLine.h"
#include "car.h"
#include "math.h"
#include <QDebug>

const int maxDistance = 3;

HexaLine::HexaLine(const Point& center, double radius, int size) : _size{size}
{
    _line.reserve(size);

    Point Curent(center.getX(), center.getY());
    double yCenter = center.getY();
    double xCenter = center.getX();
    _line.push_back(Hexagon(Point(xCenter, yCenter), radius));
    double diff = _line[0].getPoint(1).getX() - xCenter;
    xCenter += 2 * diff;

    for(int i = 1; i < size; ++i)
    {
        _line.push_back(Hexagon(Point(xCenter, yCenter), radius));
        xCenter = xCenter + (2*diff);
    }
}

Hexagon HexaLine::getHexagon(int i) const
{
    return _line[i];
}

int HexaLine::getSize() const
{
    return _size;
}

double HexaLine::calculDistance(Point point1, Point point2) const
{
    return sqrt(pow(point1.getX() - point2.getX(), 2) - pow(point1.getY() - point2.getY(), 2));
}

bool HexaLine::isClose(Car* car) const
{
    for(int i = 0; i < _size; ++i)
    {
        for(int j = 0; j < 6; ++j)
        {
            if(calculDistance(car -> getPosition(), _line[i].getPoint(j)) < maxDistance)
            {
                return true;
            }
        }
    }
    return false;
}

