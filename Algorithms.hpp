#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "Graph.hpp"

namespace ariel{

class Algorithms{

public:
    static void DFS(const Graph& myGraph,size_t vertex,std ::vector<bool>& visited);
    static bool isConnected(const Graph& g);
    static std::string shortestPath(const Graph& g , int start , int end );
    static bool containsCircleHelper(const Graph& myGraph, size_t ver, size_t parent, std ::vector<bool>& visited, std::vector<int>& verInCircle);
    static bool isContainsCycle(const Graph& myGraph);
    static bool isBipartite(const Graph& myGraph);
    static bool negativeCycle(const Graph& myGraph);

};
} // namespace ariel
#endif