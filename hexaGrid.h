#ifndef HEXAGRID_H
#define HEXAGRID_H

#include "hexaLine.h"

class Simulation;

class HexaGrid
{
    public :
        HexaGrid(const Point & FirstCenter, double radius, int lineSize, int colSize);

        int getColSize() const;
        std::vector<Hexagon> getHexagons();
        void getHexagons(std::vector<Hexagon>& Hexagons);

        HexaLine getHexaLine(int hexaline) const;

    private :
        int _colSize;
        int _lineSize;
        std::vector<HexaLine> _column;
};

#endif // HEXAGRID_H
