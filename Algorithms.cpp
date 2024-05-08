#include "Algorithms.hpp"
#include "Graph.hpp"

namespace ariel{
    Algorithms algorithms;
    
    void Algorithms::DFS(const Graph& myGraph,size_t vertex,std ::vector<bool>& visited){     //want to implement the DFS algo 
        visited[vertex]=true;      //will mark the current vertex as visited in the same index
        for (size_t i=0; i<myGraph.getNumVertices();i++){
            if(myGraph.isEdge(vertex,i) && !visited[i]){  // check if the conditions for running DFS exist 
                DFS(myGraph,i,visited);      //run DFS
            }
        }
                
    }

    bool Algorithms::isConnected(const Graph& myGraph){
        int numVertices = myGraph.getNumVertices();
        std::vector<bool> visited (static_cast<size_t>(numVertices),false);     
        algorithms.DFS(myGraph,0,visited);   //run DFS on the first vertex
        for(size_t i =0 ; i<numVertices ; i++){    //loop over all the vertices in the graph
            if(!visited[i]){       //check if a vertex has been visited if it had the graph isn't connected to that vertex
                return false;
            }
        }
        return true;    // if we visited all vertices then all are connected(also the graph is connected)
    }
        bool Algorithms::containsCircleHelper(const Graph& myGraph,size_t ver, std ::vector<bool>& visited, std::vector<bool>& currVisit){
            if(!visited[ver]){
                visited[ver]=true;
                currVisit[ver]=true;
            
                for(size_t i =0; i<myGraph.getNumVertices(); i++){
                    if(myGraph.isEdge(ver,i) && !visited[i] && isContainsCycle(myGraph)){
                        return true;
                    }
                    else if(currVisit[i]){
                        return true;
                    }
                }
            }
            currVisit[ver]=false;
            return true;    
        }


        bool  Algorithms::isContainsCycle(const Graph& myGraph){
            size_t totalVer=static_cast<size_t>(myGraph.getNumVertices());
            std::vector<bool> visited(totalVer,false);
            std::vector<bool>currVisit(totalVer,false);
            
            for(int i=0;i<totalVer;++i){
                if (containsCircleHelper(myGraph,static_cast<size_t>(totalVer),visited,currVisit)){
                    return true;
                }
            }
            return false;
        }
        std::string Algorithms ::shortestPath(const Graph& g , int start , int end ){
            
        }

        



}