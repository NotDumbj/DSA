#include <iostream>
#include <vector>

#include "graph.h"

using namespace std;

int main() {
    Graph g;

    g.addEdge(0, 1, 4);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 4, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 1, 7);
    g.addEdge(2, 4, 9);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 1, 5);

    cout << "Adjacency Matrix:" << endl;
    g.display();

    cout << "\n\nAdjacency Matrix After Removing 2 Edges :" << endl;
    g.removeEdge(2, 1);
    g.removeEdge(2, 4);
    g.display();

    return 0;
}
