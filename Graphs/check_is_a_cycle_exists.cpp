#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<int> *l;
    bool isUndir;
public:
    Graph(int V, bool isUndir = false) {
        this -> V = V;
        l = new list<int> [V];
        this -> isUndir = isUndir;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        if(isUndir) {
            l[v].push_back(u);
        }
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

    // Check for cycles in a undirected graph 
    bool isCycleUndir(int src, vector<bool> &vis, int parent) {
        vis[src] = true;

        list<int> neighbours = l[src];
        for(auto neigh : neighbours) {
            if(!vis[neigh]) {
                if(isCycleUndir(neigh, vis, src)) {
                    return true;
                }
            } else if(neigh != parent) return true;
        }
        return false;
    }

    bool checkCycleUndir() {
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(isCycleUndir(i, vis, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

    // Check for cycles in a directed graph 
    bool isCycleDir(int src, vector<bool> &vis, vector<bool> &recPath) {
        vis[src] = true;
        recPath[src] = true;

        list<int> neighbours = l[src];

        for(int v : neighbours) {
            if(!vis[v]) {
                if(isCycleDir(v, vis, recPath)) {
                    return true;
                }
            } else {
                if(recPath[v]) {
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    bool checkCycleDir() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(isCycleDir(i, vis, recPath)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph graph(5, true);

    // graph.addEdge(0, 1);
    // graph.addEdge(0, 2);
    // graph.addEdge(0, 3);
    // graph.addEdge(1, 2);
    // graph.addEdge(3, 4);

    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    graph.print();
 
    if(graph.checkCycleUndir()) {
        cout << "There exists some cycle in the graph." << endl;
    } else {
        cout << "There does not exist a cycle in the graph." << endl;
    }
}