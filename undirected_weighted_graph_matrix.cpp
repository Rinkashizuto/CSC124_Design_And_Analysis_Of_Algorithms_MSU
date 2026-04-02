#include <iostream>

const int MAX = 30;
#define INFINITY 999

class Graph{
    private:
    int adjMatrix[MAX][MAX];
    int vertices;

    public:
    Graph(int v = 0);
    Graph(const Graph &other);

    void addVertex();
    void addEdges(int u, int v, int weight);

    void display();

    void dijkstra(int startVertex);
    void dijkstra_display();
};

Graph::Graph(int v){
    if(v > MAX){
        vertices = MAX;
    }
    else{
        vertices = v;
    }

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            adjMatrix[i][j] = INFINITY;
        }
    }
}

Graph::Graph(const Graph& other){
    this->vertices = other.vertices;
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            adjMatrix[i][j] = other.adjMatrix[i][j];
        }
    }
}

void Graph::addVertex(){
    if(vertices < MAX){
        vertices++;
    }
    else{
        std::cout << "Error Maximum Reached!\n";
    }
}

void Graph::addEdges(int u, int v, int weight){
    if(u  >= 0 && u < vertices && v >= 0 && v < vertices){
        int highNode = (u > v) ? u : v;
        if(highNode >= vertices){
            vertices = highNode + 1;
        }
        
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }
    else{
        std::cout << "Invalid Edge\n";
    }

}


void Graph::display(){
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            if(adjMatrix[i][j] == INFINITY){
                std::cout << "INF" << "\t";
                continue;
            }
            std::cout << adjMatrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void Graph::dijkstra(int startVertex)
{
    int distance[MAX];
    bool visited[MAX];


    int min_index;
    int min_value;
    
    for(int i = 0; i < vertices; i++){
        distance[i] = INFINITY;
        visited[i] = false;
    }

    distance[startVertex] = 0;

    for(int i = 0; i < vertices; i++){
        min_value = INFINITY;
        min_index = -1;
        for(int j = 0; j < vertices; j++){
            if(visited[j] == false && distance[j] < min_value){
                min_value = distance[j];
                min_index = j;
            }
        }

        visited[min_index] = true;

        for(int v = 0; v < vertices; v++){
            if(!visited[v] && adjMatrix[min_index][v] != INFINITY && distance[min_index] != INFINITY){
                if(distance[v] > distance[min_index] + adjMatrix[min_index][v]){
                    distance[v] = distance[min_index] + adjMatrix[min_index][v];
                }
            }
        }

    }

}