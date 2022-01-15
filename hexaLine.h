#ifndef HEXALINE_H
#define HEXALINE_H

#include "hexagon.h"
#include "car.h"

class HexaLine
{
    public :
        HexaLine(const Point& First, double radius, int size);

        Hexagon getHexagon(int i) const;

        int getSize() const;
        double calculDistance(Point point1, Point point2) const;
        bool isClose(Car* car) const;

    private :
        std::vector<Hexagon> _line;
        int _size;
};

#endif // HEXALINE_H
