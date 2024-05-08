#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "Graph.hpp"

namespace ariel{

class Algorithms{

public:
    void DFS(const Graph& myGraph,size_t vertex,std ::vector<bool>& visited);
    static bool isConnected(const Graph& g);
    std::string shortestPath(const Graph& g , int start , int end );
    bool  containsCircleHelper(const Graph& myGraph,size_t ver, std ::vector<bool>& visited, std::vector<bool>& currVisit);
    bool isContainsCycle(const Graph& myGraph);
    static bool isBipartite(const Graph& g);
    static bool negativeCycle(const Graph& g);

};
} // namespace ariel
#endif