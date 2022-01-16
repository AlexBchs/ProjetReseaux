#ifndef HEXAGON_H
#define HEXAGON_H

#include "point.h"
#include "math.h"
#include <vector>
#include <QColor>

class Hexagon
{
    public :
        Hexagon(const Point& center, double radius, std::vector<double> color = { 255.0, 255.0, 0.0 }, double transparance = 0.0);

        Point getTop() const;
        Point getTopRight() const;
        Point getBottomRight() const;
        Point getBottom() const;
        Point getBottomLeft() const;
        Point getTopLeft() const;

        Point getPoint(int nbPoint)const;

        std::vector<double> getColor();
        void setColor(std::vector<double> qColor);

        double gettransparance() const;
        void settransparance(double transparance);

        bool contains(const Point& P)const;

    private :
        std::vector<Point> _listPoint;
        static constexpr double const& PI = M_PI;
        double _radius;
        std::vector<double> color;
        double _transparance;
};

#endif // HEXAGON_H
