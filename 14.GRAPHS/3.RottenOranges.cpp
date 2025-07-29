#include <bits/stdc++.h>
using namespace std;


int orangesRotting(vector<vector<int>>& grid) {
int n=grid.size();
int m=grid[0].size();
//{{r,c},t}
queue<pair<pair<int,int>,int>> q;
   vector<vector<int>>vis(n,vector<int>(m,0));
   
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]==2){
            q.push({{i,j},0});
            vis[i][j]=2;
        }else{
            vis[i][j]=0;
        }
    }
   }
   int tm=0;
   int dr[]={-1,0,1,0};
   int dc[]={0,1,0,-1};

    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        tm=max(tm,t);
        q.pop();

        for(int i=0;i<4;i++){
            int nrow=r+dr[i];
            int ncol=c+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
                

                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol]=2;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]!=2){
                return -1; 
            }
        }
    }
    return tm;
}

int main() {
    int n,m;
    cin >> n >>m;

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

  int result = orangesRotting(arr);


  cout <<"the minimum number of minutes required is " <<result << endl;



    return 0;
}
