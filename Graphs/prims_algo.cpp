#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>> *l;
public:
    Graph(int V) {
        this -> V = V;
        l = new list<pair<int, int>> [V];
    }

    void addEdge(int u, int v, int w) {
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    int primsAlgo(int src) {
        // Make a min heap of [wt(u, v), v]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> mst(V, false);

        int ans = 0;
        pq.push(make_pair(0, src));

        while(!pq.empty()) {
            int u = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if(!mst[u]) {
                mst[u] = true;
                ans += cost;
                list<pair<int, int>> neigh = l[u];

                for(pair<int, int> n : neigh) {
                    int v = n.first;
                    int currWt = n.second;
                    pq.push(make_pair(currWt, v));
                }
            }
        }
        return ans;
    }

    void primsAlgo2(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> mst(V, false);
        vector<pair<int, int>> edges;

        int ans = 0;
        pq.push(make_pair(0, src));

        while(!pq.empty()) {
            int u = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if(!mst[u]) {
                mst[u] = true;
                ans += cost;
                edges.push_back({u, cost});
                list<pair<int, int>> neigh = l[u];

                for(pair<int, int> n : neigh) {
                    int v = n.first;
                    int currWt = n.second;
                    pq.push(make_pair(currWt, v));
                }
            }
        }

        cout << "The edges are: " << endl;
        for(auto p : edges) {
            cout << p.first << " -> " << p.second << endl;
        }
    }
};

int main() {
    Graph graph(5);
    
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);
    
    int minCost = graph.primsAlgo(0);
    cout << "The total cost of MST is: " << minCost << endl;

    graph.primsAlgo2(0);
}