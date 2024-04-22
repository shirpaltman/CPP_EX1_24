#ifndef GRAPH_H
#define GRAPH_H
#include <vector>


namespace ariel{

class Graph{
private:
    std::vector<std:: vector<int>> connections;
    int totalVertices;


public:
    Graph();   //constructor
    Graph(int totalVertices) : totalVertices(totalVertices),connections(totalVertices,std::vector<int>(totalVertices,0)){}
    void loadGraph (const std :: vector<std ::vector <int>>&matrix);
    void printGraph()const;


    int getNumVertices ()const{
        return totalVertices;
    }

    bool isEdge(int ver1 , int ver2) const{
        if(ver1 < 0 || ver2 < 0 || ver1 >= totalVertices || ver2 >= totalVertices){          // checking that the ver is in the range
            return false;
        }
        return connections[ver1][ver2] != 0;
    }

};
} // namespace ariel
#endif
