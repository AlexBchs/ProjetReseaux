#include "graph.h"
#include "simulation.h"

#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <QDebug>

using std::string;

Graph::Graph(const string& mapFileName, Simulation& simulation) : _mapFileName{mapFileName}
{
    extractMap(simulation);
}


bool Graph::extractMap(Simulation& simulation)
{
    std::ifstream mapFile{_mapFileName};
    if(!mapFile.is_open())
    {
        //qDebug() << "Error map file not found";
        return false;
    }

    char indic;
    mapFile >> indic;

    if(indic == 'n')
    {
        int nbNodes;
        mapFile >> nbNodes;
        for(int i=0; i<nbNodes; ++i)
        {
            int id, x, y;
            mapFile >> id >> x >> y;
            simulation.getNodes().push_back(new Node(id, x, y));
        }
    }

    mapFile >> indic;

    if(indic == 'w')
    {
        int nbWays;
        mapFile >> nbWays;
        for(int i=0; i<nbWays; ++i)
        {
            int id, idNode1, idNode2;
            mapFile >> id >> idNode1 >> idNode2;
            simulation.getRoutes().push_back( new Route(id, simulation.getNodes()[idNode1], simulation.getNodes()[idNode2]));
        }
    }

    mapFile.close();

    return true;
}
