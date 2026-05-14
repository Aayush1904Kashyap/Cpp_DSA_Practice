#include <bits/stdc++.h>
using namespace std;

 int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int,int>> adj[n];
    for(auto it:roads){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    } 
    
priority_queue<
pair<long long,int>,
vector<pair<long long,int>>,
greater<pair<long long,int>>
> pq;

vector<long long> dist(n,1e18);
    dist[0]=0;
    vector<int>ways(n,0);
    ways[0]=1;

    pq.push({0,0}); //{dist,node}

    int mod=int(1e9+7);

    while(!pq.empty()){
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();

          if(dis > dist[node]) continue;

        for(auto it:adj[node]){
            int adjNode=it.first;
            int wt=it.second;

            if(dis+wt < dist[adjNode]){
                dist[adjNode]=dis+wt;
                pq.push({dist[adjNode],adjNode});
                ways[adjNode]=ways[node];
            }
            else if(dis+wt == dist[adjNode]){
                ways[adjNode]=(ways[adjNode]+ways[node])%mod;
            }
        }
    }
    return ways[n-1]%mod;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> roads;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        roads.push_back({u,v,w});
    }

    int ans=countPaths(n,roads);
    cout<<ans<<endl;
    return 0;
}