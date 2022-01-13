#ifndef HEXAGON_H
#define HEXAGON_H

#include "point.h"
#include <vector>



class Hexagon
{
    public :
        Hexagon(const Point& center, double radius, std::vector<double> color ={ 0.0,0.0,0.0 }, double transparance =0.0);

        Point getTop() const;
        Point getTopRight() const;
        Point getBottomRight() const;
        Point getBottom() const;
        Point getBottomLeft() const;
        Point getTopLeft() const;

        Point operator[](int i)const;

        std::vector<double> getColor()const;
        void setColor(std::vector<double> color);

        double gettransparance() const;
        void settransparance(double transparance);

        bool contains(const Point& P)const;

    private :
        std::vector<Point> _listPoint;
        static constexpr double const& PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196;
        double _radius;
        std::vector<double> _color;
        double _transparance;
};

#endif // HEXAGON_H
