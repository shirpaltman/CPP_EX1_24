#include "Graph.hpp"
#include <vector>
#include <stack>
#include <stdexcept>
#include <iostream>


namespace ariel{
    class Graph{
    private:
        std::vector<std::vector<int>> adjMat;
        int totalVertices;

    public:
        Graph(int totalVertices) : totalVertices(totalVertices), adjMat(static_cast<int>(totalVertices), std :: vector<int> (static_cast<int>(totalVertices),0)){

        }
        
        void printGraph()const{
            for(int i=0;i<totalVertices;i++){
                for(int j=0;j<totalVertices;j++){
                    std::cout <<adjMat[i][j]<< " ";
                }
                std::cout << std::endl;
            }
        }



        void loadGraph (const std :: vector<std :: vector<int>>& mat){
            if (mat[0].size() != totalVertices||mat.size() != totalVertices){
                throw std ::invalid_argument("There is a problem! \n The Matrix dimensions do not match the number of vertices.");
            }
            adjMat =mat ;  
        }


    } ;

}





