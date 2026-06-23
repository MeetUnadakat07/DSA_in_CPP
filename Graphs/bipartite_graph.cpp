#include<iostream>
#include<vector>
#include<list>
#include<queue>
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

    bool isBipartite() {
        queue<int> q;
        vector<int> color(V, -1);

        q.push(0);
        color[0] = 0;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            list<int> neighbours = l[curr];

            for(int v : neighbours) {
                if(color[v] == -1) {                    // unvisited
                    color[v] = (color[curr] == 0) ? 1 : 0;
                    q.push(v);
                } else {
                    if(color[v] == color[curr]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Graph graph(5);
    
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(0, 3);
    
    cout << "Unweighted graph: " << endl;
    graph.print();

    if(graph.isBipartite()) {
        cout << "The graph is a bipartite graph" << endl;
    } else {
        cout << "The graph is not a bipartite graph" << endl;
    }
}