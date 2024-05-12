#include "Algorithms.hpp"
#include "Graph.hpp"
#include <limits>
#include <queue>

using namespace std;
using namespace ariel;
namespace    Algorithms{

    //Algorithms algorithms;

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
        vector<bool> visited (static_cast<size_t>(numVertices),false);     
        DFS(myGraph,0,visited);   //run DFS on the first vertex
        for(size_t i =0 ; i<numVertices ; i++){    //loop over all the vertices in the graph
            if(!visited[i]){       //check if a vertex has been visited if it had the graph isn't connected to that vertex
                return false;
            }
        }
        return true;    // if we visited all vertices then all are connected(also the graph is connected)
    }
    bool Algorithms ::containsCircleHelper(const Graph& myGraph,size_t ver, std ::vector<bool>& visited, std::vector<bool>& currVisit){
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


    bool Algorithms::isContainsCycle(const Graph& myGraph){
        size_t totalVer=static_cast<size_t>(myGraph.getNumVertices());
        vector<bool> visited(totalVer,false);
        vector<bool>currVisit(totalVer,false);
            
        for(size_t i=0;i<totalVer;++i){
            if (containsCircleHelper(myGraph,static_cast<size_t>(totalVer),visited,currVisit)){
                return true;
            }
        }
        return false;
    }

        
    void relax (size_t u,size_t v,int weight,std::vector<int> &dist,std::vector<int> &parent){
        if ((static_cast<size_t>(dist[u]))!= std::numeric_limits<int>:: max()&& (static_cast<size_t>(dist[u]+weight))< (static_cast<size_t>(dist[v]))){
            dist[v]=dist[u]+ weight;
            parent[v]=u;
        }
    }
    bool bellmanFordAlgo(const Graph& myGraph , int start,std::vector<int>&dist,std::vector<int>&parent ){
        
        size_t totalVertices =(static_cast<size_t> (myGraph.getNumVertices()));
        //giving the dist array the value of infinity
        dist.assign((static_cast<size_t>(myGraph.getNumVertices())),std::numeric_limits<int>::max());
        //giving the parent array the value of -1 (which means no parent)
        parent.assign(totalVertices,-1);
        dist[static_cast<size_t>(start)]=static_cast<size_t>(0);       //give the first vertex distance with the value 0


        //run the relax function on the edges reapeatedly
        for (size_t i= 0 ; i<myGraph.getNumVertices()-1;++i){
            for(size_t u = 0; u<myGraph.getNumVertices();++u){
                for(size_t v = 0; v<myGraph.getNumVertices();++v){
                    if(myGraph.isEdge(u,v)){
                        int edgeWeight=myGraph.getWeight(u,v);
                            relax(u,v,edgeWeight,dist,parent);    
                    }
                }
            }
        }
            //checking if there is in the graph negetive cycle

        for(std::vector<int>::size_type u = 0; u<myGraph.getNumVertices();++u){
            for(std::vector<int>::size_type v = 0; v<myGraph.getNumVertices();++v){
                if(myGraph.isEdge(u,v)){
                    int edgeWeight=myGraph.getWeight(u,v); 
                    if(dist[u]!=std::numeric_limits<int>::max() && dist[u]+edgeWeight < dist[v]){       //check if after the |v| -1 times of relax ,the edge can still be relaxed
                        return false; //A negetive cycle has been detected   
                    }
                }
            }
        }
        return true;
    }

    std::string Algorithms ::shortestPath(const Graph& myGraph , int start , int end ){
        std::vector<int> dist,parent;
        if(!bellmanFordAlgo(myGraph,start,dist,parent)){
            return "The graph contains negative cycle";
        }
        if (start < 0 || start >= myGraph.getNumVertices() || end <0 || end>=myGraph.getNumVertices()){
            return "check the end and start vertices something is abnormal";
        }
        std::string structureShortPath;
        size_t curr=static_cast<size_t>(end);
        while (curr != start){
            structureShortPath = std::to_string(curr) + "->" + structureShortPath;
            curr = static_cast<size_t>(parent[curr]);
        }
        structureShortPath = std::to_string(start) + "->" + structureShortPath;
        return structureShortPath;
    }



    bool Algorithms::negativeCycle(const Graph& myGraph){
        std::vector <int> dist,parent;
        return !bellmanFordAlgo(myGraph,0,dist,parent);
    }
 
    bool Algorithms::isBipartite(const Graph& myGraph){
        size_t totalVertices =(static_cast<size_t> (myGraph.getNumVertices()));
        vector<string> color(totalVertices,"WHITE");
        for(size_t i = 0; i<totalVertices; i++){
            if(color[i]== "WHITE"){
                queue<size_t> q;
                q.push(i);
                color[i]="BLUE";

                while(!q.empty()){
                    size_t u = q.front();
                    q.pop();

                    for (size_t v ;v<myGraph.getNeighbors(static_cast<size_t>(u)).size();++v){
                       // size_t v = myGraph.getNeighbors(static_cast<size_t>(u))
                        if(color[v]==color[u]){
                            return false;
                        }
                        else if (color[v]== "WHITE"){
                            if(color[u]== "BLUE"){
                                color[v]= "RED";
                            } 
                            else{
                                color[v]= "BLUE";
                            }
                            q.push(v);
                        }
                    }
                }
            }
        }
        return true;
    }
            
            



        



}