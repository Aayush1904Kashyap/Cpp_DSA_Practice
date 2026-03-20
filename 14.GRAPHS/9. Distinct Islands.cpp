#include <bits/stdc++.h>
using namespace std;

int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    set<vector<pair<int,int>>> st;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1){
                vector<pair<int,int>> vec;
                queue<pair<int,int>> q;
                q.push({i,j});
                grid[i][j] = 0;

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    vec.push_back({x-i,y-j});

                    int dx[] = {-1,0,1,0};
                    int dy[] = {0,1,0,-1};

                    for(int k=0;k<4;k++){
                        int newX = x + dx[k];
                        int newY = y + dy[k];

                        if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY] == 1){
                            q.push({newX,newY});
                            grid[newX][newY] = 0;
                        }
                    }
                }
                st.insert(vec);
            }
        }
    }
    return st.size();
}

int main() {
    int n,m;
    cin >> n >>m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << countDistinctIslands(arr) << "\n";

    return 0;
}

