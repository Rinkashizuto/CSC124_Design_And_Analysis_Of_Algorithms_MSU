#include <iostream>

const int MAX = 20;

class Graph{
    public:

    Graph(int v);
    Graph(const Graph &other);
    ~Graph();
    void displayAdjacencyMatrix();
    void createGraph(int edges[][2], int edge_size);

    private:
    int matrix[MAX][MAX];
    int vertices = 1;
};

Graph::Graph(int v = 1){
    /*
    Precondition : User passes a int vertices. vertices defaults to one if no pass occurs.
    Postcondition : Initalizes a matrix and assigns its edges to its respected vertices.
    */

    if(v > MAX) return;
    vertices = v;

    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            matrix[i][j] = 0;
        }
    }


}

Graph::~Graph(){

}

Graph::Graph(const Graph &other){

}

void Graph::createGraph(int edges[][2], int edge_size){
    /*
    Precondition : Required a int array and edge size.
    Postcondition : Applies the edges to the matrix.

    */
        for(int i = 0; i < edge_size; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        if(u < vertices && v < vertices){
            matrix[u][v] = 1;
        }
    }

}

void Graph::displayAdjacencyMatrix(){
    std::cout << "Adjacency Matrix\n";
    for(int i = 0; i < vertices; i++ ){
        for(int j = 0; j < vertices; j++){
            std::cout << "{" << matrix[i][j] << "} ";
        }
        std::cout << std::endl;
    }
}

int main() {

    int Vertices = 4;
    int Edges[][2] = { {0, 1}, {1, 2}, {2, 0}, {1,3} };
    int Edge_Size = 4;
    Graph graph(Vertices);
    graph.createGraph(Edges, Edge_Size);
    graph.displayAdjacencyMatrix();

    return 0;
}