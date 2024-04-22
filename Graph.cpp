#include "Graph.hpp"
#include <vector>
#include <stack>


namespace ariel{
    class Algorithms{
    public:

        static void DFS (const Graph& myGraph,int vertex,std ::vector<bool>& visited){     //want to implement the DFS algo 
            visited[vertex]=true;      //will markk the current vertex as visited in the same index
            for (int i=0; i<myGraph.getNumVertices();i++){
                if(myGraph.isEdge(vertex,i) && !visited[i]){  // check if the conditions for running DFS exist 
                    DFS(myGraph,i,visited);      //run DFS
                }
            }
   
        }


        static bool isConnected(const Graph& myGraph){
            int numVertices = myGraph.getNumVertices();
            std::vector<bool> visited (numVertices,false);
            DFS(myGraph,0,visited);     //run DFS on the first vertex
            for(int i =0 ; i<numVertices ; i++){    //loop over all the vertices in the graph
                if(!visited[i]){       //check if a vertex has been visited if it had the graph isn't connected to that vertex
                    return false;
                }
            }
            return true;    // if we visited all vertices then all are connected(also the graph is connected)

        }

        
    };

} 



