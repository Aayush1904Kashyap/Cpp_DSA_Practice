#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], vector<int> &vis) {
    vis[src] = 1;
    queue<pair<int,int>> q;
    q.push({src, -1});

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();

        for(auto adjacentNode : adj[node]) {
            if(!vis[adjacentNode]) {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if(adjacentNode != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int n, vector<int> adj[]) {
    vector<int> vis(n+1, 0);

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(detect(i, adj, vis)) return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adjList[n+1];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // print adjacency list
    for(int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for(auto x : adjList[i]) cout << x << " ";
        cout << "\n";
    }

    cout << (isCycle(n, adjList) ? "Cycle Present\n" : "No Cycle\n");

    return 0;
}
