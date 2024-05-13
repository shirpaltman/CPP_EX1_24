***
### 🎓 Welcome to Shir's Algorithms Adventure! 🚀

### Get ready to embark on an exciting journey through the fascinating algorithms I imlementeted in this assigment here you have a README for what's to come in first taks for this semster 🌟 ###

***
### Algorithms ### 
*** 
### DFS
This function performs Depth-First Search (DFS) traversal starting from the specified vertex in the given graph (myGraph). It marks visited vertices in the provided vector visited.

 ### isConnected

This function checks whether the given graph (g) is connected or not. It returns true ifthe graph is connected, otherwise false.

### shortestPath
This function finds the shortest path from the starting vertex (start) to the ending vertex (end) in the given graph (g). It returns a string representing the shortest path.

### isCycle
This function checks whether the given graph contains a cycle and returns information about if it found.It utilizes DFS traversal to detect cycles.

### dfsVisit
During DFS search traversal, this function performs the visit operation for each vertex in the graph . It is used as a helper function for cycle detection algorithms.

### buildCycleString
Upon detecting a cycle in the graph, this function constructs a string represntation of the cycle using the information provided by the previous node vector.
### isContainsCycle
This function checks whether the given graph (myGraph) contains any cycles. It returns true if a cycle is found, otherwise false.

### isBipartite
This function determines whether the given graph (myGraph) is bipartite or not. It returns true if the graph is bipartite, otherwise false.

### negativeCycle
This function checks whether the given graph (myGraph) contains a negative cycle. It returns true if a negative cycle is found, otherwise false.


***
### Graph ### 
***

The `Graph` class is the core component of this library, offering functionalities for representing and manipulating graphs.

`Attributes:`
### adjMat
 A 2D vector representing the adjacency matrix of the graph.
### totalVertices
 The total number of vertices in the graph.

`Methods:`
### getNumVertices
Returns the total number of vertices in the graph.
### getAdjMat
Returns a constant reference to the adjacency matrix of the graph.
### isEdge
Checks if there is an edge between two vertices.
### loadGraph
Loads a graph from a given adjacency matrix.
### printGraph
Prints the graph in a readable format.
### getWeight
Returns the weight of the edge between two vertices.
### getNeighbors
 Returns a vector of neighboring vertices for a given vertex.