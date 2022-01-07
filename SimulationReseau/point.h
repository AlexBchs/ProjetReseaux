#ifndef POINT_H
#define POINT_H

class Point
{
    public :
        Point();
        Point(double x, double y);
        Point(int x, int y);

        virtual ~Point();

        double getX() const;
        double getY() const;

        void setX(double x);
        void setY(double y);

        void moveTo(double x, double y);
        void moveOf(double dx, double dy);

    private :
        double _x;
        double _y;
};

#endif // POINT_H
