#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]){

    priority_queue<
    pair<int, int>,
    vector<pair<int, int>>, 
    greater<pair<int, int>>
    > pq;

    vector<int>vis(V, 0);
    pq.push({0, 0});

    int sum = 0;

    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int wt = it.first;

        if(vis[node]) continue;

        vis[node] = 1;
        sum += wt;

        for(auto &it : adj[node]) {
            int adjNode = it[0];
            int edW = it[1];

            if(!vis[adjNode]) {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    cout << spanningTree(V, adj) << endl;

    return 0;
}

//time complexity: O(E log V) where E is the number of edges and V is the number of vertices in the graph. This is because we are using a priority queue to store the edges based on their weights, and each edge is processed at most once. The operations on the priority queue (insertion and extraction) take O(log V) time.
//space complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.