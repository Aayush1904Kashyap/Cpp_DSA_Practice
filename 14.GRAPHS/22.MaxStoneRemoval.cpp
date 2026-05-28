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

 int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;
        int n=stones.size();
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);

        unordered_map<int,int>stoneNodes;

        for(auto it:stones){
            int u=it[0];
            int v=it[1]+maxRow+1;    
            ds.unionBySize(u,v);
            stoneNodes[u]=1;
            stoneNodes[v]=1;
        }

        int cnt=0;
        for(auto it:stoneNodes){
            if(ds.findUPar(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;

    }

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> arr[i][j];
        }
    }

    cout << removeStones(arr) << endl;

    return 0;
}