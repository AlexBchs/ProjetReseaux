#include "node.h"
#include "route.h"
#include <iostream>

using std::cout;

Node::Node(int id, int x, int y) : Point{x,y}, _id{id}, _connectedRoutes(0)
{}

Node::~Node()
{
    for(unsigned long int i=0; i< _connectedRoutes.size(); ++i)
    {
        _connectedRoutes[i] = nullptr;
    }
}

int Node::getId() const
{
    return _id;
}


vector<Route*>& Node::getConnectedRoutes()
{
    return _connectedRoutes;
}
