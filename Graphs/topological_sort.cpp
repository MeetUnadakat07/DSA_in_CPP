#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
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

    void printTopo(stack<int> &s) {
        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    void topoHelper(int src, vector<bool> &vis, stack<int> &s) {
        vis[src] = true;

        list<int> neighbours = l[src];

        for(int v : neighbours) {
            if(!vis[v]) {
                topoHelper(v, vis, s);
            }
        }

        s.push(src);
    }

    void topoSort() {
        vector<bool> vis(V, false);
        stack<int> s;
        for(int v = 0; v < V; v++) {
            if(!vis[v]) {
                topoHelper(v, vis, s);
            }
        }
        printTopo(s);
    }

    void calculateIndegree(vector<int> &indeg) {
        for(int u = 0; u < V; u++) {
            list<int> neigh = l[u];
            for(int v : neigh) {
                indeg[v]++;
            }
        }
    }

    // Kahn's algorithm 
    void topoSort2() {
        vector<int> indeg(V, 0);
        calculateIndegree(indeg);
        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            list<int> neigh = l[curr];

            for(int v : neigh) {
                indeg[v]--;
                if(indeg[v] == 0) {     // No pending dependencies
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph graph(6);

    graph.addEdge(5, 0);
    graph.addEdge(5, 2);
    graph.addEdge(4, 0);
    graph.addEdge(0, 3);
    graph.addEdge(4, 1);
    graph.addEdge(3, 1);

    graph.print();

    int src = 5, dest = 1;
    cout << "The sequence of processing using Topological sort is: ";
    graph.topoSort();

    cout << "The sequence of processing using Kahn's algorithm is: ";
    graph.topoSort2();
}