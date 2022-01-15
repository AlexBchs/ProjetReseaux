#ifndef POINT_H
#define POINT_H

class Point
{
    public :
        Point();
        Point(double x, double y);
        Point(int x, int y);

        virtual ~Point();

        void setX(double x);
        void setY(double y);

        double getX() const;
        double getY() const;

        void moveTo(double x, double y);
        void moveOf(double dx, double dy);

    private :
        double _x;
        double _y;
};

#endif // POINT_H
