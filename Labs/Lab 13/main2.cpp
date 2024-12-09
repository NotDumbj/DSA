#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int start, const vector<vector<pair<int, int>>>& graph) {
    vector<int> distances(graph.size(), INT_MAX);
    vector<int> previous(graph.size(), -1);
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (current_distance > distances[current_node]) continue;

        for (auto [neighbor, weight] : graph[current_node]) {
            int distance = current_distance + weight;

            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                previous[neighbor] = current_node;
                pq.push({distance, neighbor});
            }
        }
    }


    cout << "Shortest Distances from node " << start << ":\n";
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    cout << "\nPrevious Nodes:\n";
    for (int i = 0; i < previous.size(); ++i) {
        cout << "Node " << i << ": " << previous[i] << endl;
    }
}

int main() {
    vector<vector<pair<int, int>>> graph = {
        {{1, 1}, {2, 2}}, 
        {{3, 3}, {4, 1}}, 
        {{5, 5}},         
        {},               
        {},               
        {}                
    };

    int start_node = 0;
    dijkstra(start_node, graph);

    return 0;
}
