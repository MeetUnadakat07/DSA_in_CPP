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

    void printPathHelper(int src, int dest, vector<int> &path, vector<bool> &vis) {
        if(src == dest) {
            for(int i : path) {
                cout << i << " ";
            }
            cout << dest << " "<< endl;
            return;
        }

        vis[src] = true;
        path.push_back(src);
        list<int> neighbours = l[src];

        for(int v : neighbours) {
            if(!vis[v]) {
                printPathHelper(v, dest, path, vis);
            }
        }
        path.pop_back();
        vis[src] = false;
    }

    void printPaths(int src, int dest) {
        vector<bool> vis(V, false);
        vector<int> path;
        printPathHelper(src, dest, path, vis);
    }

};

int main() {
    Graph graph(6, true);

    graph.addEdge(5, 0);
    graph.addEdge(5, 2);
    graph.addEdge(4, 0);
    graph.addEdge(0, 3);
    graph.addEdge(4, 1);
    graph.addEdge(3, 1);

    graph.print();

    cout << "The paths are: " << endl;
    int src = 5, dest = 1;
    graph.printPaths(src, dest);
}