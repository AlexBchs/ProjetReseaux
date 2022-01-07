#ifndef ROUTE_H
#define ROUTE_H

#include "node.h"

class Route
{
    public :
        Route(int id, Node* node1, Node* node2);
        ~Route();

        int getId() const;
        Node* getNode1();
        Node* getNode2();

        int toX(Node* startingNode) const;
        int toY(Node* startingNode) const;

        double nodesDistance() const;

    private :
        int _id;
        Node* _node1;
        Node* _node2;
};

#endif // ROUTE_H
