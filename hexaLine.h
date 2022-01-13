#ifndef HEXALINE_H
#define HEXALINE_H

#include "hexagon.h"

class HexaLine
{
    public :
        HexaLine(const Point& First, double radius, int size);

        Hexagon operator[](int i) const;

        int getSize() const;

    private :
        std::vector<Hexagon> _line;
        int _size;
};

#endif // HEXALINE_H
