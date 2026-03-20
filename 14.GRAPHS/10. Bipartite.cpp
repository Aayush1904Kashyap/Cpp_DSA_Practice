#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<int> adj[]) {
    
    vector<int> color(V + 1, -1);   // -1 means uncolored

    // Check all components
    for (int start = 1; start <= V; start++) {
        
        if (color[start] == -1) {
            
            queue<int> q;
            q.push(start);
            color[start] = 0;   // Start coloring with 0

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto it : adj[node]) {
                    
                    // If uncolored → assign opposite color
                    if (color[it] == -1) {
                        color[it] = 1 - color[node];
                        q.push(it);
                    }
                    // If same color → Not bipartite
                    else if (color[it] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V + 1];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isBipartite(V, adj)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
