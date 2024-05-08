#include "Graph.hpp"
#include <vector>
#include <stack>
#include <stdexcept>
#include <iostream>


namespace ariel{


        //Graph(int totalVertices) : totalVertices(totalVertices), adjMat(static_cast<int>(totalVertices), std :: vector<size_t> (static_cast<int>(totalVertices),0)){}
        

        int Graph::getNumVertices ()const{
            return this -> totalVertices;
        }
        
        const std::vector<std::vector<int>>& Graph::getAdjMat()const{
            return this->adjMat;
        }


        bool Graph::isEdge(unsigned int ver1 , unsigned int ver2)const{
            try{
                return this->adjMat.at(ver1).at(ver2) != 0;
            }
            catch (const std:: out_of_range &e){
                throw std :: out_of_range ("the vertex in the index you have asked is out of bounds.");
            }
       
        
        }

        void Graph::printGraph()const{
            for(std::vector<int>::size_type i=0;i<adjMat.size();i++){
                for(std ::vector<int>::size_type j=0;j<adjMat[i].size();j++){
                    std::cout <<adjMat[i][j]<< " ";
                }
                std::cout << std::endl;
            }
        }



        void Graph ::loadGraph (const std :: vector<std :: vector<int>>& mat){
            if (mat[0].size() != totalVertices||mat.size() != totalVertices){
                throw std ::invalid_argument("There is a problem! \n The Matrix dimensions do not match the number of vertices.");
            }
            adjMat =mat ;  
        }




};





