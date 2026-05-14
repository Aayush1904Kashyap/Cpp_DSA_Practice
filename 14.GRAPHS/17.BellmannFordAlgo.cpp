#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V,vector<vector<int>>& edges,int S){
    vector<int>dist(V,1e9);
    dist[S]=0;

    for(int i=0;i<V-1;i++){
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            if(dist[u] !=1e9 && dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    // for negative cycle detection
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];

        if(dist[u] !=1e9 && dist[u]+wt<dist[v]){
            return {-1};
        }
    }
    return dist;
}

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>>edges;
    for(int i=0;i<E;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }

    vector<int> shortestPath=bellmanFord(V,edges,0);
    for(int i=0;i<V;i++){
        if(shortestPath[i]==1e9){
            cout<<"-1 ";
        }
        else{
            cout<<shortestPath[i]<<" ";
        }
    }
    return 0;
}

//Time Complexity: O(V*E)
//Space Complexity: O(V)