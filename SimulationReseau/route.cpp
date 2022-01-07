#include "route.h"
#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

Route::Route(int id, Node* node1, Node* node2) : _id{ id }, _node1 { node1 }, _node2{ node2 }
{
    //Add the current route to the nodes
    _node1->getConnectedRoutes().push_back(this);
    _node2->getConnectedRoutes().push_back(this);
}

Route::~Route()
{
    _node1 = nullptr;
    _node2 = nullptr;
}

int Route::getId() const
{
    return _id;
}

Node* Route::getNode1()
{
    return _node1;
}

Node* Route::getNode2()
{
    return _node2;
}

int Route::toX(Node* startingNode) const
{
    if(startingNode == _node1) return _node2->getX() - _node1->getX();
    else if(startingNode == _node2) return _node1->getX() - _node2->getX();
    else return 0;
}

int Route::toY(Node* startingNode) const
{
    if(startingNode == _node1) return _node2->getY() - _node1->getY();
    else if(startingNode == _node2) return _node1->getY() - _node2->getY();
    else return 0;
}

double Route::nodesDistance() const
{
    return sqrt((_node1->getX()-_node2->getX()) * (_node1->getX()-_node2->getX()) +
                (_node1->getY()-_node2->getY()) * (_node1->getY()-_node2->getY()));
}
