#include <bits/stdc++.h>
using namespace std;

void floydWarshall(int V, vector<vector<int>>& graph) {

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][k] != 1e9 && graph[k][j] != 1e9) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V, vector<int>(V, 1e9));

    for (int i = 0; i < V; i++) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u][v] = wt;
    }

    floydWarshall(V, graph);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1e9) {
                cout << "-1 ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}