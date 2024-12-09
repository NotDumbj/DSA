#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int v, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[v] = true;
    cout << v << " ";

    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
    }
}

void bfs(int start, const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}


int main()
{
    vector<vector<int>> graph{
        {1, 2},                                                        //       0
        {3, 4},                                                        //   1   ||  2 
        {5},                                                           // 3 , 4 ||  5
        {},
        {},
        {}
    };
    vector<bool> visited(graph.size(), false);
    cout << "Depth First Search Traversal :" << endl;
    dfs(0, visited, graph);

    cout << "\nBreadth First Search Traversal :" << endl;
    bfs(0, graph);


    return 0;
}