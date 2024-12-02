#include <iostream>

const int MAXVERTEXS = 5;

struct Edge
{
    bool adj;
    int weight;
    friend std::ostream& operator<<(std::ostream& out, const Edge& edge){
        out << "["  << edge.weight << "] ";
        return out;
    }	
};



class Graph {
private:
    Edge adjMatrix[MAXVERTEXS][MAXVERTEXS];

public:
    // Constructor: Initialize the adjacency matrix with 0 (no edges)
    Graph() {
        for (int i = 0; i < MAXVERTEXS; i++) {
            for (int j = 0; j < MAXVERTEXS; j++) {
                adjMatrix[i][j] = {0,0};
            }
        }
    }

    // Add an edge from vertex1 to vertex2
    void addEdge(int vertex1, int vertex2, int weight) {
        adjMatrix[vertex1][vertex2].adj = true;
        adjMatrix[vertex1][vertex2].weight= weight;
    }

    // Remove an edge from vertex1 to vertex2
    void removeEdge(int vertex1, int vertex2) {
        adjMatrix[vertex1][vertex2].adj = false;
        adjMatrix[vertex1][vertex2].weight= 0;
    }

    // Display the adjacency matrix
    void display() {
        for (int i = 0; i < MAXVERTEXS; i++) {
            for (int j = 0; j < MAXVERTEXS; j++) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};
