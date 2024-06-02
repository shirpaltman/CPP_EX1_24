/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
*/


#include "Algorithms.hpp"
#include "Graph.hpp"
#include <limits>
#include <queue>
#include <iostream>

using namespace std;
using namespace ariel;
const int INF = numeric_limits<int>::max(); // infinity
namespace Algorithms{

    const unsigned int WHITE = 0;
    const unsigned int GREY = 1 ;
    const unsigned int BLACK = 2;

    // Algorithms algorithms;

    void DFS(const Graph &myGraph, size_t vertex, std ::vector<bool> &visited){                           // want to implement the DFS algo
        visited[vertex] = true; // will mark the current vertex as visited in the same index
        for (size_t i = 0; i < myGraph.getNumVertices(); i++){
            if (myGraph.isEdge(vertex, i) && !visited[i]){      // check if the conditions for running DFS exist
                DFS(myGraph, i, visited); // // Recursively call DFS on adjacent vertices
            }
        }
    }

    bool isConnected(const Graph &myGraph){
        int numVertices = myGraph.getNumVertices();
        if(numVertices == 0){
            cout << "the graph is connected" << endl;
            return true;
        }
        vector<bool> visited(static_cast<size_t>(numVertices), false);
        DFS(myGraph, 0, visited); // run DFS on the first vertex
        for (size_t i = 0; i < numVertices; i++){ // loop over all the vertices in the graph
            if (!visited[i]){ // check if a vertex has been visited if it had the graph isn't connected to that vertex
                return false;
            }
        }
        return true; // if we visited all vertices then all are connected(also the graph is connected)
    }


    void relax(size_t u, size_t v, int weight, std::vector<int> &dist, std::vector<int> &parent)
    {
            // Relaxation step to update shortest distance and parent if a shorter path is found
        if ((static_cast<size_t>(dist[u])) != std::numeric_limits<int>::max() && (static_cast<size_t>(dist[u] + weight)) < (static_cast<size_t>(dist[v])))
        {
            dist[v] = dist[u] + weight;
            parent[v] = u;
        }
    }
    bool bellmanFordAlgo(const Graph &myGraph, int start, std::vector<int> &dist, std::vector<int> &parent)
    {

        size_t totalVertices = (static_cast<size_t>(myGraph.getNumVertices()));
        // giving the dist array the value of infinity
        dist.assign((static_cast<size_t>(myGraph.getNumVertices())), std::numeric_limits<int>::max());
        // giving the parent array the value of -1 (which means no parent)
        parent.assign(totalVertices, -1);
        dist[static_cast<size_t>(start)] = static_cast<size_t>(0); // give the first vertex distance with the value 0

        // run the relax function on the edges reapeatedly (|V| -1)
        for (size_t i = 0; i < myGraph.getNumVertices() - 1; ++i)
        {
            for (size_t u = 0; u < myGraph.getNumVertices(); ++u)
            {
                for (size_t v = 0; v < myGraph.getNumVertices(); ++v)
                {
                    if (myGraph.isEdge(u, v))
                    {
                        int edgeWeight = myGraph.getWeight(u, v);
                        relax(u, v, edgeWeight, dist, parent);
                    }
                }
            }
        }
        // checking if there is in the graph negetive cycle

        for (std::vector<int>::size_type u = 0; u < myGraph.getNumVertices(); ++u)
        {
            for (std::vector<int>::size_type v = 0; v < myGraph.getNumVertices(); ++v)
            {
                if (myGraph.isEdge(u, v))
                {
                    int edgeWeight = myGraph.getWeight(u, v);
                    if (dist[u] != std::numeric_limits<int>::max() && dist[u] + edgeWeight < dist[v])
                    {                 // check if after the |v| -1 times of relax ,the edge can still be relaxed
                        return false; // A negetive cycle has been detected
                    }
                }
            }
        }
        return true;  //NO NEGETIVE CYCLE WAS DETECTED
    }

    std::string shortestPath(const Graph &myGraph, int start, int end)
    {
        std::vector<int> dist, parent;
        if (!bellmanFordAlgo(myGraph, start, dist, parent)){
            return "The graph contains negative cycle";
        }
            // Check if start and end vertices are valid
        if (start < 0 || start >= myGraph.getNumVertices() || end < 0 || end >= myGraph.getNumVertices()){
            return "check the end and start vertices something is abnormal";
        }
        std::string structureShortPath;
        size_t current = (size_t)end;
        if(dist[current] == INF){
            cout << "there is no path" << endl;
            return "-1";
        }
        structureShortPath = std::to_string(current) ;
        current = static_cast<size_t>(parent[current]);

        // Reconstruct shortest path using parent array
        while (current != start){
            structureShortPath = std::to_string(current) + "->" + structureShortPath;
            current = static_cast<size_t>(parent[current]);
        }
        structureShortPath = std::to_string(start) + "->" + structureShortPath;
        return structureShortPath;
    }

    bool negativeCycle(const Graph &myGraph){
        std::vector<int> dist, parent;

        // Check if a negative cycle exists in the graph using Bellman-Ford algorithm
        return !bellmanFordAlgo(myGraph, 0, dist, parent);
    }

    bool isBipartite(const Graph &myGraph){
        size_t totalVertices = (static_cast<size_t>(myGraph.getNumVertices()));
        vector<string> color(totalVertices, "WHITE"); // Color of vertices

        // Perform BFS from each vertex to check bipartiteness
        for (size_t i = 0; i < totalVertices; i++){
            if (color[i] != "WHITE"){
                continue;  // Skip if vertex already colored
            }
            queue<size_t> q;
            q.push(i);
            color[i] = "BLUE";  // Color the first vertex

            while (!q.empty()){
                size_t u = q.front();
                q.pop();

                for (size_t v = 0; v < totalVertices; ++v){
                    if ((myGraph.getAdjMat()[u][v] != 0 || myGraph.getAdjMat()[v][u] != 0) && u != v){
                        if (color[v] == "WHITE") {
                         // Assign alternate color to adjacent vertices
                            if (color[u] == "BLUE"){
                                color[v] = "RED";
                            }
                            else
                            {
                                color[v] = "BLUE";
                            }
                            q.push(v);
                        }
                        else if (color[v] == color[u])
                        {
                            std::cout << "the graph is not bipartite" << endl;
                            return false;      
                        }
                    }
                }
            }
        }
        std::cout << "the graph is bipartite" << endl;
        return true;
    }
    // Perform DFS to find cycles
    string isCycle(const Graph& myGraph){
        size_t totalVer =static_cast<size_t>(myGraph.getNumVertices());
        vector<unsigned int > color(totalVer,WHITE);  // Color of vertices during traversal
        vector<unsigned int> previous(totalVer,totalVer);  // Store the parent of each vertex
        // Iterate over all vertices to find cycles
        for(size_t i =0 ; i<totalVer; ++i){
            if (color[i] == WHITE){
                unsigned int temp = dfsVisit(myGraph,i,color,previous);
                if(temp!=totalVer){
                    return buildCycleString(temp,previous);    // Return the cycle if found
                }
            }
        }
        return "0"  ;   //Return "0" if no cycle is found

    }

    // Helper function for DFS traversal to detect cycles
    unsigned int dfsVisit(const Graph& myGraph,size_t u, vector<unsigned int>& color,vector<unsigned int >& parent){
        color[u]= GREY;  // Mark the vertex as being visited
        for(size_t v =0 ; v<myGraph.getNumVertices(); ++v){
            if(myGraph.isEdge(u,v)&& v!=u){
                if(color[v]== WHITE){
                    parent[v]=u;       // Set the parent of the vertex
                    return dfsVisit(myGraph,v,color,parent);

                }
                else{
                    if(color[v]==GREY && v!=parent[u]){
                        parent[v]=u;
                        return v;   // Return the vertex if a cycle is detected
                    }
                }
            }
        }
        color[u]=BLACK;
        return static_cast<unsigned int> (myGraph.getNumVertices());    // Return if no cycle is found
    }


    // Function to build a string representation of the cycle
    string buildCycleString(unsigned int firstInCycle,const vector<unsigned int> & prev){
        string cyclePath = to_string(firstInCycle);
        unsigned int c= firstInCycle; 
        do{
            c=prev[c];     // Traverse the cycle path using the parent array
            cyclePath +="<-" + to_string(c);  
        }
        while (c != firstInCycle);    // Continue until the cycle is complete
        return cyclePath;    
    }


    // Function to check if the graph contains a cycle
    bool isContainsCycle( const Graph & myGraph){
        string cycle=isCycle(myGraph);   // Call isCycle to find a cycle in the graph
        if (cycle != "0"){
            cout<<"Cycle found: " <<cycle<< endl;      // Print the cycle if found
            return true;
        }
        else{
            cout<< "0" <<endl;     // Print "0" if no cycle is found
            return false;
        }
    } 
};
