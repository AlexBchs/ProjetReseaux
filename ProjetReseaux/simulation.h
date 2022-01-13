#ifndef SIMULATION_H
#define SIMULATION_H

#include "hexaGrid.h"
#include "car.h"
#include "route.h"
#include "node.h"
#include "graph.h"

using std::vector;

class Simulation
{
    public :
        Simulation();
        ~ Simulation();

        int getNumberOfCars() const;
        HexaGrid getGrid();
        vector<Car*>& getCars();
        vector<Node*>& getNodes();
        vector<Route*>& getRoutes();
        int getSpeedSimulation();

        Node* randomNode();

        void addCar();
        void removeACar();

        void update();

    private :
        vector<Car*> _cars;
        vector<Node*> _nodes;
        vector<Route*> _routes;
        HexaGrid* _grid;
        double _hexaRadius;
        int _colSizeGrid;
        int _lineSizeGrid;
        int speedSimulation;
        Graph* _graph;
};

#endif // SIMULATION_H
