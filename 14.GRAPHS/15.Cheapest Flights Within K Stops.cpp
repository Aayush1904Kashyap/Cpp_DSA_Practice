#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int,int>> adj[n];
    for(auto it:flights){
        adj[it[0]].push_back({it[1],it[2]});
    }

    queue<pair<int,pair<int,int>>>q; //{stops,{node,price}}
    q.push({0,{src,0}});
    vector<int>dist(n,1e9);
    dist[src]=0;

    while(!q.empty()){
        auto it=q.front();
        q.pop();

        int stops=it.first;
        int node=it.second.first;
        int price=it.second.second;

        if(stops > k) continue;

        for( auto it:adj[node]){
            int adjNOde=it.first;
            int wt=it.second;

            if(price+wt < dist[adjNOde] && stops <= k){
                dist[adjNOde]=price+wt;
                q.push({stops+1,{adjNOde,dist[adjNOde]}});
            }
        }
    }

    if(dist[dst] == 1e9) return -1;
    return dist[dst];



}


int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> flights;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        flights.push_back({u,v,w});
    }

    int src,dst,k;
    cin>>src>>dst>>k;

    int ans=findCheapestPrice(n,flights,src,dst,k);
    cout<<ans<<endl;
    return 0;
}