#include <iostream>
#include "undirected_weighted_graph_matrix.cpp"


int main(){
    int v = 6;
    Graph g(v);

    int start = 0;
    std::string fileName = "test";

    int edges[][3] = {{0, 1, 10}, {1, 2, 5}, {2, 3, 8},
                      {3, 0, 7},  {0, 4, 3}, {1, 4, 12}};
    for(int i = 0; i < v; i++){
        g.addEdges(edges[i][0], edges[i][1], edges[i][2]);
    }

    g.loadToFile(fileName);

    g.display();



    g.dijkstra(start);
    g.dijkstraDisplay(start);
}