#include <bits/stdc++.h>
using namespace std;

// DFS to traverse connected components
void dfs(int node, vector<vector<int>> &adjLs, vector<int> &vis) {
    vis[node] = 1;
    for (auto it : adjLs[node]) {
        if (!vis[it]) {
            dfs(it, adjLs, vis);
        }
    }
}

int numOfProvinces(vector<vector<int>> &adj, int V) {
    // Convert adjacency matrix to adjacency list
    vector<vector<int>> adjLs(V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1 && i != j) {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }

    vector<int> vis(V, 0);
    int cnt = 0;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i, adjLs, vis);
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int provinces = numOfProvinces(arr, n);
    cout << "Number of provinces = " << provinces << endl;

    return 0;
}
