#include <bits/stdc++.h>
using namespace std;

vector<int>Bfs(int V,vector<int>adj[]){
    vector<int> vis(V + 1, 0);
    vis[1]=1;
    queue<int>q;
    q.push(1);
    vector<int>bfs;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}

void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ls){
    vis[node]=1;
    ls.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }

}

vector<int>dfsOfGraph(int V,vector<int>adj[]){
    vector<int> vis(V + 1, 0);
    int start=1;
    vector<int>ls;
    dfs(start,adj,vis,ls);
    return ls;
}

int main(){
    int n,m;
    cin>>n>>m;

    //graph storing using matrix
    // int adj[n+1][n+1];
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u][v]=1;
    //     adj[v][u]=1;
    // }

    //graph storing using list

   vector<int>adjList[n+1];
   for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
   }

    // print adjacency list
    for(int i=1; i<=n; i++){
        cout << i << " -> ";
        for(auto x : adjList[i]){
            cout << x << " ";
        }
        cout << "\n";
    }

    vector<int>result1=Bfs(n,adjList);
    vector<int>result2=dfsOfGraph(n,adjList);
    cout<<"BFS: ";
    for(auto x:result1){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"DFS: "<<endl;
    for(auto x:result2){
        cout<<x<<" ";
    }

    cout<<endl;
    return 0;

}