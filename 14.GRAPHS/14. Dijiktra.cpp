#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstraSet(int V, vector<vector<int>> adj[]) {
    int src=0;

   set<pair<int,int>>s;


    vector<int>dist(V,1e9);
    dist[src]=0;

    s.insert({0,src});

    while(!s.empty()){
        int node=s.begin()->second;
        int dis=s.begin()->first;
        s.erase(s.begin());

        for(auto it:adj[node]){
            int adjNode=it[0];
            int wt=it[1];

            if(dis+wt < dist[adjNode]){
                if(dist[adjNode] != 1e9){
                    s.erase({dist[adjNode],adjNode});
                }
                dist[adjNode]=dis+wt;
                s.insert({dist[adjNode],adjNode});
            }
        }
    }

    return dist;

}

vector<int> dijkstraPQ(int V, vector<vector<int>> adj[]) {
    int src=0;

    priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
    >pq;

    vector<int>dist(V,1e9);
    dist[src]=0;

    pq.push({0,src});

    while(!pq.empty()){
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();

        for(auto it:adj[node]){
            int adjNode=it[0];
            int wt=it[1];

            if(dis+wt < dist[adjNode]){
                dist[adjNode]=dis+wt;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }



    return dist;

}

int main(){
    int V,E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    for(int i=0;i<E;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    vector<int> dist1 = dijkstraPQ(V, adj);
    vector<int> dist2 = dijkstraSet(V, adj);
    for(int i=0;i<V;i++){
        cout << dist1[i] << " ";
    }
    cout << endl;
    for(int i=0;i<V;i++){
        cout << dist2[i] << " ";
    }
    cout << endl;

}