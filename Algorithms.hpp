#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "Graph.hpp"

namespace ariel{

class Algorithms{

public:
    void  DFS (const Graph& myGraph,int vertex,std ::vector<bool>& visited);
    static bool isConnected(const Graph& g);
    static std::vector<int> shortestPath(const Graph& g , int start , int end );
    static bool isContainsCycle(const Graph& g);
    static bool isBipartite(const Graph& g);
    static bool negativeCycle(const Graph& g);

};
} // namespace ariel
#endif