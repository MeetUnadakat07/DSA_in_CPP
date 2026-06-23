#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int V) {
        this -> V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print() {
        for(int u = 0; u < V; u++) {
            list<int> neighbours = l[u];
            cout << u << ": ";
            for(int v : neighbours) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

class WeightedGraph {
    int V;
    list<pair<int, int>> *l;
public:
    WeightedGraph(int V) {
        this -> V = V;
        l = new list<pair<int, int>> [V];
    }

    void addEdge(int u, int v, int w) {
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    void print() {
        for(int u = 0; u < V; u++) {
            list<pair<int, int>> neighbours = l[u];
            cout << u << ": ";
            for(auto v : neighbours) {
                cout << "("<< v.first << ", " << v.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(5);
    
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    
    cout << "Unweighted graph: " << endl;
    graph.print();
    
    // For weighted graphs 
    WeightedGraph wgraph(5);
    
    wgraph.addEdge(0, 1, 5);
    wgraph.addEdge(1, 2, 1);
    wgraph.addEdge(2, 3, 1);
    wgraph.addEdge(2, 4, 2);
    wgraph.addEdge(1, 3, 3);
    
    cout << "Weighted graph: " << endl;
    wgraph.print();
}