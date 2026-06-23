#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
using namespace std;

// For making an edge list
class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this -> v = v;
        this -> wt = wt;
    }
};

void bellmanFord(int src, vector<vector<Edge>> &graph, int V) { // O(V*E)
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i = 0; i < V - 1; i++) {    // O(V)
        for(int u = 0; u < V; u++) {    // O(E)
            for(Edge e : graph[u]) {
                if(dist[u] != INT_MAX && dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    // To check if the weights change even after V - 1 iterations
    for(int u = 0; u < V; u++) {
        for(Edge e : graph[u]) {
            if(dist[u] != INT_MAX && dist[e.v] > dist[u] + e.wt) {
                cout << "Negative weight cycle detected\n";
                return;
            }
        }
    }

    for(int i = 0; i < V; i++) {
        cout << i << " -> " << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<Edge>> graph(V);

    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, -4});
    graph[2].push_back({3, 2});
    graph[3].push_back({4, 4});
    graph[4].push_back({1, -1});

    bellmanFord(4, graph, V);
}