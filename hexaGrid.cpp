#include "hexaGrid.h"

HexaGrid::HexaGrid(const Point& FirstCenter, double radius, int lineSize, int colSize) : _colSize{colSize}, _lineSize{lineSize}
{
    HexaLine line1 = HexaLine(FirstCenter, radius, lineSize);
    _column.reserve(colSize);
    _column.push_back(line1);

    double xImpair = line1[0].getTopRight().getX();
    double xPair = FirstCenter.getX();

    double yPair = FirstCenter.getY()+3*radius;
    double yImpair = line1[0].getTopRight().getY()+radius;

    for(int i=1; i<colSize; ++i)
    {
        if(i%2 == 0)
        {
            _column.push_back(HexaLine(Point(xPair, yPair), radius, lineSize));
            yPair += 3 * radius;
        }
        else
        {
            _column.push_back(HexaLine(Point(xImpair, yImpair), radius, lineSize));
            yImpair += 3 * radius;
        }
    }
}

int HexaGrid::getColSize() const
{
    return _colSize;
}

HexaLine HexaGrid::operator[](int i) const
{
    return _column[i];
}


std::vector<Hexagon> HexaGrid::getHexagons()
{
    std::vector<Hexagon> hexagons;
    hexagons.reserve(_colSize * _lineSize);
    for(int i=0; i<_colSize; ++i)
    {
        for(int j=0; j<_lineSize; ++j)
        {
            hexagons.push_back(_column[i][j]);
        }
    }
    return hexagons;
}
