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

void dijkstra(int src, vector<vector<Edge>> &graph, int V) {
    // Make a min heap 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // dist[v], v (sorting based on dist)
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    pq.push(make_pair(0, src));

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        vector<Edge> edges = graph[u];

        for(Edge e : edges) {
            if(dist[e.v] > dist[u] + e.wt) {
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v], e.v));
            }
        }
    }

    for(int i = 0; i < dist.size(); i++) {
        cout << i << " -> " << dist[i] << endl;
    }
}

int main() {
    int V = 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));

    graph[2].push_back(Edge(4, 3));

    graph[3].push_back(Edge(5, 1));

    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(5, 5));

    dijkstra(0, graph, V);
}