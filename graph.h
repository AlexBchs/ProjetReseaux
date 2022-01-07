#ifndef GRAPH_H
#define GRAPH_H

#include <string>

class Simulation;

class Graph
{
    public :
        Graph(const std::string& mapFileName, Simulation& simulation);
        bool extractMap(Simulation& simulation);

    private :
        std::string _mapFileName;
};

#endif // GRAPH_H
