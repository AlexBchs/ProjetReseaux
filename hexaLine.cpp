#include "hexaLine.h"

HexaLine::HexaLine(const Point& center, double radius, int size) : _size{size}
{
    _line.reserve(size);

    Point Curent(center.getX(), center.getY());
    double xCenter = center.getX();
    double yCenter = center.getY();
    _line.push_back(Hexagon(Point(xCenter, yCenter), radius));
    double diff = _line[0][1].getX() - xCenter;
    xCenter += 2 * diff;

    for(int i=1;i<size;++i,xCenter+=(2*diff))
    {
        _line.push_back(Hexagon(Point(xCenter, yCenter), radius));
    }
}

Hexagon HexaLine::operator[](int i) const
{
    return _line[i];
}

int HexaLine::getSize() const
{
    return _size;
}
