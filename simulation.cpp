#include "simulation.h"

#include <ctime>
#include <string>
#include <QDir>
#include <cstdlib>
#include <QDebug>

const int tailleMaxTableaux = 100;
const int radiusHexa = 50, tailleColonne = 400, tailleLigne = 400;
const Point Origine = Point(5.0, 5.0);

Simulation::Simulation() : _nodes{0}, _routes{0}, speedSimulation{20}
{
    srand(time(NULL));

    _cars.reserve(tailleMaxTableaux);
    _nodes.reserve(tailleMaxTableaux);
    _routes.reserve(tailleMaxTableaux);
    _hexaRadius = radiusHexa;
    _colSizeGrid = tailleColonne;
    _lineSizeGrid = tailleLigne;

    _grid = new HexaGrid(Origine, _hexaRadius, _lineSizeGrid, _colSizeGrid);
    _graph = new Graph("../SimulationReseau/Ressources/map.txt", *this);

    addCar();
}

Simulation::~Simulation()
{
    for(unsigned long int i=0; i<_nodes.size(); ++i)
    {
        delete _nodes[i];
    }

    for(unsigned long int i=0; i<_routes.size(); ++i)
    {
        delete _routes[i];
    }

    for(unsigned long int i=0; i<_cars.size(); ++i)
    {
        delete _cars[i];
    }

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
    _cars.push_back(new Car(node, new Signal(), node->getConnectedRoutes()[0], speedSimulation));
}

void Simulation::removeACar()
{
    if(_cars.size() > 0)
    {
        delete _cars[_cars.size()-1];
        _cars.pop_back();
    }
    else
    {
        qDebug() << "[ERROR] Impossible de retirer une voiture. (Aucune voiture présente)";
    }
}

void Simulation::update()
{
    qDebug() << "Tick Update";
    for(unsigned long int i=0; i<_cars.size(); ++i)
    {
        _cars[i]->moveOnTheRoute();
    }

    double r, g, b;

    bool atLeastOneCar;

    /*for(int i = 0; i< _grid -> getColSize(); ++i)
    {
        for(int j = 0; j < _lineSizeGrid; ++j)
        {
            atLeastOneCar = true;
            r = g = b = 0;

            for(unsigned long int i=0; i < _cars.size(); ++i)
            {
                if(_cars[i]->exist())
                {
                    Car* car = _cars[i];
                    if(_grid[i][j].isClose(car))
                    {
                        atLeastOneCar = true;
                        r += (car->getSignal()->getFrequency());
                        g += (car->getSignal()->getRayon());
                        b += (car->getSignal()->getStrength());
                    }
                }
            }
        }
    }*/
}
