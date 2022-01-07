#ifndef NODE_H
#define NODE_H

#include "point.h"
#include <vector>

using std::vector;

class Route;

class Node : public Point
{
    public :
        Node(int id, int x, int y);
        virtual ~Node();

        int getId() const;

        vector<Route*>& getConnectedRoutes();

    private :
        int _id;
        vector<Route*> _connectedRoutes;
};

#endif // NODE_H
