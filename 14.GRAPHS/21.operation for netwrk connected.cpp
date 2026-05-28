#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
    vector<int> parent, rank,size;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }

        int findUPar(int node) {
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u,int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v) return;

            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        
        void unionBySize(int u,int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v) return;

            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        } 
    };

int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];    
            if(ds.findUPar(u) == ds.findUPar(v)){
                extraEdges++;
            }
            else{
                ds.unionByRank(u,v);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i) == i){
                cnt++;
            }
        }
        int ans=cnt-1;
        if(extraEdges>=ans){
            return ans;
        }
        else{
            return -1;
        }
    }

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> connections(m, vector<int>(2));
    for(int i=0;i<m;i++){
        cin>>connections[i][0]>>connections[i][1];
    }
    int result = makeConnected(n, connections);
    cout << result << endl;


    return 0;
}