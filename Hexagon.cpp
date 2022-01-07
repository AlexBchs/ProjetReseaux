#include "hexagon.h"
#include <algorithm>
#include <math.h>

Hexagon::Hexagon(const Point& center, double radius, std::vector<double> color, double transparance) : _radius{radius}
{
    _color = color;
    _transparance = transparance;
    double numPoints = 6.0;
    _listPoint.reserve(static_cast<int> (numPoints));

    double angle = 2.0* PI / numPoints;

    double centerX = center.getX();
    double centerY = center.getY();

    double x, y;

    //Construction des points dans le sens anti-trigo en commencant par le point en haut
    for(int i=0; i<numPoints; ++i)
    {
        x= centerX+radius*sin(i*angle);
        y= centerY+radius*cos(i*angle);
        Point  P= Point(x, y);
        _listPoint.push_back(P);
    }
}

Point Hexagon::getTop() const
{
    return _listPoint[0];
}

Point Hexagon::getTopRight() const
{
    return _listPoint[1];
}

Point Hexagon::getBottomRight() const
{
    return _listPoint[2];
}

Point Hexagon::getBottom() const
{
    return _listPoint[3];
}

Point Hexagon::getBottomLeft() const
{
    return _listPoint[4];
}

Point Hexagon::getTopLeft() const
{
    return _listPoint[5];
}

Point  Hexagon::operator[](int i) const
{
    return _listPoint[i];
}

std::vector<double> Hexagon::getColor() const
{
    return _color;
}

void Hexagon::setColor(std::vector<double> color)
{
    _color=color;
}

double Hexagon::gettransparance() const
{
    return _transparance;
}

void Hexagon::settransparance(double transparance)
{
    _transparance=transparance;
}

bool Hexagon::contains(const Point& P) const
{
    bool test = false;
    double yMax= getTop().getY();
    double yMin= getBottom().getY();

    double xMin= getTopLeft().getX();
    double xMax= getTopRight().getX();

    double X= P.getX();
    double Y= P.getY();

    if(X >= xMin && X <= xMax)
    {
        if(Y > getTopLeft().getY())
        {
            double distanceY = getTopLeft().getY() - yMax;
            double distanceX = getTop().getX() - xMin;
            double coefictienDroite = distanceY * xMin + distanceX * getTopLeft().getY();


            double distanceY2 = getTopRight().getY() - yMax;
            double distanceX2 = getTop().getX() - xMax;
            double coefictienDroite2 = distanceY2 * xMax + distanceX2 * getTopRight().getY();


            double coeficienDroitePoint = distanceY * P.getX() + distanceX * P.getY();
            double coeficienDroitePoint2 = distanceY2 * P.getX() + distanceX2 * P.getY();

            test = coeficienDroitePoint <= coefictienDroite && coeficienDroitePoint2 >= coefictienDroite2;
        }
        else if(Y < getBottomLeft().getY())
        {
            double distanceY = getBottomLeft().getY() - yMin;
            double distanceX = getBottom().getX() - getBottomLeft().getX();
            double coefictienDroite = distanceY * getBottomLeft().getX() + distanceX * getBottomLeft().getY();


            double distanceY2 = getBottomRight().getY() - yMin;
            double distanceX2 = getBottom().getX() - getBottomRight().getX();
            double coefictienDroite2 = distanceY2 * getBottomRight().getX() + distanceX2 * getBottomRight().getY();


            double coeficienDroitePoint = distanceY * P.getX() + distanceX * P.getY();
            double coeficienDroitePoint2 = distanceY2 * P.getX() + distanceX2 * P.getY();

            test = coeficienDroitePoint >= coefictienDroite && coeficienDroitePoint2 <= coefictienDroite2;
        }

        else
        {
            test = true;
        }
    }
    return test;
}

