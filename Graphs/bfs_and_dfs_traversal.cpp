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

    void bfs() {        // O(V + E)
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            list<int> neighbours = l[u];
            for(int v : neighbours) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
    
    void dfsHelper(int u, vector<bool> &vis) {      // O(V + E)
        vis[u] = true;
        cout << u << " ";
        
        list<int> neighbours = l[u];
        for(int v : neighbours) {
            if(!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }
    
    void dfs() {
        int u = 0;
        vector<bool> vis(V, false);
        dfsHelper(u, vis);
        cout << endl;
    }
    
    // Finding path using DFS 
    bool pathHelper(int src, int dest, vector<bool> &vis) {
        if(src == dest) return true;

        vis[src] = true;
        list<int> neighbours = l[src];

        for(int v : neighbours) {
            if(!vis[v]) {
                if(pathHelper(v, dest, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool hasPath(int src, int dest) {
        vector<bool> vis(V, false);
        return pathHelper(src, dest, vis);
    }

    // Finding path using BFS 
    bool hasPath2(int src, int dest) {
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(src);
        vis[src] = true;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            if(dest == u) return true;

            list<int> neighbours = l[u];
            for(int v : neighbours) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return false;
    }
};

int main() {
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    graph.print();
    cout << "BFS Traversal: ";
    graph.bfs();

    cout << "DFS Traversal: ";
    graph.dfs();

    int src = 0, dest = 6;
    if(graph.hasPath2(src, dest)) {
        cout << "There exists path between " << src << " and " << dest << endl;
    }  else {
        cout << "There does not exist path between " << src << " and " << dest << endl;
    }
}