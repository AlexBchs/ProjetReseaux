#ifndef CAR_H
#define CAR_H

#include "point.h"
#include "signal.h"
#include "route.h"
#include "node.h"

#include <cmath>
#include <vector>

using std::vector;

class Car
{
    public :
        Car(Node* startNode, Signal* signal, Route* route, double speed);
        ~Car();

        Point getPosition() const;
        Signal* getSignal() const;
        Route* getRoute() const;
        double getSpeed() const;
        vector<Car*>& getConnectedCars();
        bool endOfRoute() const;
        bool exist() const;

        void setPosition(int x, int y);
        void setEndOfRoute(bool endOfRoute);
        void setRoute(Route* newRoute);
        void setStartingNode(Node* newStartingNode);
        void setSpeed(double newSpeed);

        void moveTo(const Point &newPosition);

        bool inRange(const Car* OtherCar);
        void addCarCommunicating(Car* OtherCar);
        void deleteCarInRange();

        void moveOnTheRoute();
        void changeRoute(Node* endingNode, Route* finishedRoute);

        double traveledDistance() const;

    private :
        Point _position;
        Signal* _signal;
        Route* _route;
        double _speed;
        vector<Car*> _connectedCars;
        bool _endOfRoute;
        Node* _startingNode;
};

#endif // CAR_H
