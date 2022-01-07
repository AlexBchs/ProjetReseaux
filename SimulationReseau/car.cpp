#include "car.h"

#include <cstdlib>
#include<vector>

Car::Car(Node* startingNode, Signal* signal, Route *route, double speed) : _position{startingNode->getX(), startingNode->getY()},
    _signal{signal}, _route{route}, _speed{speed}, _connectedCars(0), _endOfRoute{false}, _startingNode{startingNode}
{
    _connectedCars.reserve(100);
}

Car::~Car()
{
    delete _signal;
    _startingNode = nullptr;
    _route = nullptr;
    for(unsigned long int i=0; i<_connectedCars.size(); ++i) _connectedCars[i] = nullptr;
}

Point Car::getPosition() const
{
    return _position;
}

Signal* Car::getSignal() const
{
    return _signal;
}

Route* Car::getRoute() const
{
    return _route;
}

double Car::getSpeed() const
{
    return _speed;
}

bool Car::endOfRoute() const
{
    return _endOfRoute;
}

vector<Car*>& Car::getConnectedCars()
{
    return _connectedCars;
}

void Car::setPosition(int x, int y)
{
    _position.moveTo(x, y);
}

void Car::setEndOfRoute(bool endOfRoute)
{
    _endOfRoute = endOfRoute;
}

void Car::setRoute(Route* newRoute)
{
    _route = newRoute;
}

void Car::setStartingNode(Node* newStartingNode)
{
    _startingNode = newStartingNode;
}

void Car::setSpeed(double newSpeed)
{
    _speed = newSpeed;
}


void Car::moveTo(const Point &newPosition)
{
    _position = newPosition;
}

bool Car::inRange(const Car* OtherCar)
{
    double distanceX = pow(OtherCar->getPosition().getX() - this->getPosition().getX(), 2);
    double distanceY = pow(OtherCar->getPosition().getY() - this->getPosition().getY(), 2);

    double distancePoints = sqrt(distanceX + distanceY);

    double r_other = OtherCar->getSignal()->getRayon();
    double r_this = this->getSignal()->getRayon();

    double SommeRayons = r_other + r_this;

    if(distancePoints <= SommeRayons)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Car::addCarCommunicating(Car* OtherCar)
{
    if(inRange(OtherCar))
    {
        _connectedCars.push_back(OtherCar);
    }
}

void Car::deleteCarInRange()
{
    if(!_connectedCars.empty())
    {
        for(unsigned long int i=0; i<_connectedCars.size(); ++i)
        {
            if(!inRange(_connectedCars[i]))
            {
                _connectedCars.erase( _connectedCars.begin()+i);
            }
        }
    }
}

void Car::moveOnTheRoute()
{
    _position.moveOf(_route->toX(_startingNode)*_speed, _route->toY(_startingNode)*_speed);

    if(traveledDistance() > _route->nodesDistance())
    {
        Node* endingNode;
        if(_startingNode == _route->getNode1()) endingNode = _route->getNode2();
        else endingNode = _route->getNode1();

        setPosition(endingNode->getX(), endingNode->getY());
        changeRoute(endingNode, _route);
    }
}

void Car::changeRoute(Node* endingNode, Route* finishedRoute)
{
    if(endingNode->getConnectedRoutes().size() > 1)
    {
        int iRoute;
        do
        {
            iRoute = rand() % endingNode->getConnectedRoutes().size();
        }
        while(endingNode->getConnectedRoutes()[iRoute]->getId() == finishedRoute->getId());

        setRoute(endingNode->getConnectedRoutes()[iRoute]);
    }

    setStartingNode(endingNode);
}

double Car::traveledDistance() const
{
    return sqrt((_position.getX() - _startingNode->getX()) * (_position.getX() - _startingNode->getX()) +
        (_position.getY() - _startingNode->getY()) * (_position.getY() - _startingNode->getY()));
}

