#include <bits/stdc++.h>
using namespace std;

vector<int> shortestDistance(int V, vector<int> adj[]) {

    int src = 1;

    vector<int> dist(V + 1, 1e9);

    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        for(auto it : adj[node]) {

            if(dist[node] + 1 < dist[it]) {

                dist[it] = dist[node] + 1;

                q.push(it);
            }
        }
    }

    vector<int> ans(V + 1, -1);

    for(int i = 1; i <= V; i++) {

        if(dist[i] != 1e9) {
            ans[i] = dist[i];
        }
    }

    return ans;
}

int main() {

    int V, E;
    cin >> V >> E;

    vector<int> adj[V + 1];

    for(int i = 0; i < E; i++) {

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> result = shortestDistance(V, adj);

    for(int i = 1; i <= V; i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}