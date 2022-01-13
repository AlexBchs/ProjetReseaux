#include "simulation.h"

#include <ctime>
#include <string>
#include <QDir>
#include <cstdlib>
#include <QDebug>

Simulation::Simulation() : _cars{0}, _nodes{0}, _routes{0}, speedSimulation{20}
{
    srand(time(NULL));

    _cars.reserve(100);
    _nodes.reserve(100);
    _routes.reserve(100);
    Point Origine = Point(5.0, 5.0);
    _hexaRadius = 50;
    _colSizeGrid = 400;
    _lineSizeGrid = 400;

    _grid = new HexaGrid(Origine, _hexaRadius, _lineSizeGrid, _colSizeGrid);


    _graph = new Graph("../Ressources/map.txt", *this);

    addCar();
}

Simulation::~Simulation()
{
    for(unsigned long int i=0; i<_nodes.size(); ++i) delete _nodes[i];

    for(unsigned long int i=0; i<_routes.size(); ++i) delete _routes[i];

    for(unsigned long int i=0; i<_cars.size(); ++i) delete _cars[i];

    delete _graph;
}


int Simulation::getNumberOfCars() const
{
    return _cars.size();
}

int Simulation::getSpeedSimulation()
{
    return speedSimulation;
}

HexaGrid Simulation::getGrid()
{
    return *_grid;
}

vector<Car*>& Simulation::getCars()
{
    return _cars;
}

vector<Node*>& Simulation::getNodes()
{
    return _nodes;
}

vector<Route*>& Simulation::getRoutes()
{
    return _routes;
}

Node* Simulation::randomNode()
{
    int iNode= rand() % _nodes.size();
    return _nodes[iNode];
}

void Simulation::addCar()
{
    Node* node = randomNode();
    _cars[_cars.size()-1] = new Car(node, new Signal(), node->getConnectedRoutes()[0], speedSimulation);
}

void Simulation::removeACar()
{
    if(_cars.size()>0)
    {
        delete _cars[_cars.size()-1];
        _cars.pop_back();
    }
}

void Simulation::update()
{
    qDebug() << "Tick Update";
    /*for(unsigned long int i=0; i<_cars.size(); ++i)
    {
        if(_cars[i]) _cars[i]->moveOnTheRoute();
    }

    double R;
    double G;
    double B;

    int nCarsInOneHexagon;

    for(int i=0; i< _grid.getColSize(); ++i)
    {
        for(int j=0; j<_lineSizeGrid; ++j)
        {
            _grid[i][j].setColor({ 1.0,1.0,1.0,1.0 });
            _grid[i][j].settransparance(0.0);
            nCarsInOneHexagon = 0;
            R = 0;G = 0;B = 0;

            for(unsigned long int i=0; i<_cars.size(); ++i)
            {
                if(_cars[i])
                {
                    if(_grid[i][j].contains(_cars[i]->getPosition()))
                    {
                        nCarsInOneHexagon++;
                        R += (double)(_cars[i]->getSignal()->getFrequency());
                        G += (double)(_cars[i]->getSignal()->getRayon());
                        B += (double)(_cars[i]->getSignal()->getStrength());
                    }
                }
            }

            if(nCarsInOneHexagon > 0)
            {
                //calcul rgb et transparance
                R = (R / 255.0) ;
            }
        }
    }*/
}
