/*You are given a rows x cols matrix grid representing a field of cherries where 
grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:
Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.*/

#include <bits/stdc++.h>
using namespace std;

int f(int i,int j1,int j2,vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();

    //base cases: out of bound and destination
    if(j1<0 || j1>=m || j2<0 || j2>=m){
        return -1e9;
    }

    if(i==n-1){
        if(j1==j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j1]+grid[i][j2];
        }
     }

     //explore all 9 paths combo

     int maxi=-1e9;
     for(int dj1=-1;dj1<=1;dj1++){
         for(int dj2=-1;dj2<=1;dj2++){
            if(j1==j2){
                maxi=max(maxi,grid[i][j1]+f(i+1,j1+dj1,j2+dj2,grid));
            }
            else{
                maxi=max(maxi,grid[i][j1]+grid[i][j2]+f(i+1,j1+dj1,j2+dj2,grid));
            }
         }
     }

     return maxi;

}

int fdp(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
    int n=grid.size();
    int m=grid[0].size();

    //base cases: out of bound and destination
    if(j1<0 || j1>=m || j2<0 || j2>=m){
        return -1e9;
    }
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }

    if(i==n-1){
        if(j1==j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j1]+grid[i][j2];
        }
     }

     //explore all 9 paths combo

     int maxi=-1e9;
     for(int dj1=-1;dj1<=1;dj1++){
         for(int dj2=-1;dj2<=1;dj2++){
            int val=0;
             if(j1==j2){
                 val=grid[i][j1];
             }
             else{
                 val=grid[i][j1]+grid[i][j2];
             }
             val+=fdp(i+1,j1+dj1,j2+dj2,grid,dp);
             maxi=max(maxi,val);
         }
     }

     return dp[i][j1][j2]=maxi;

}

 int cherryPickup1(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();

    return f(0,0,m-1,grid);
}

int cherryPickup2(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

    return fdp(0,0,m-1,grid,dp);
}

int cherryPickup3(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2){
                dp[n-1][j1][j2]=grid[n-1][j1];
            }
            else{
                dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi=-1e9;
                for(int dj1=-1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){
                        int val=0;
                        if(j1==j2){
                            val=grid[i][j1];
                        }
                        else{
                            val=grid[i][j1]+grid[i][j2];
                        }
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m){
                            val+=dp[i+1][j1+dj1][j2+dj2];
                        }
                        else{
                            val+=-1e9;
                        }
                        maxi=max(maxi,val);
                    }
                }
                dp[i][j1][j2]=maxi;
            }
        }
    }

    return dp[0][0][m-1];
}

int cherryPickup4(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<int>> prev(m,vector<int>(m,-1));

    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2){
                prev[j1][j2]=grid[n-1][j1];
            }
            else{
                prev[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
    }

    for(int i=n-2;i>=0;i--){
        vector<vector<int>> curr(m,vector<int>(m,-1));
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi=-1e9;
                for(int dj1=-1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){
                        int val=0;
                        if(j1==j2){
                            val=grid[i][j1];
                        }
                        else{
                            val=grid[i][j1]+grid[i][j2];
                        }
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m){
                            val+=prev[j1+dj1][j2+dj2];
                        }
                        else{
                            val+=-1e9;
                        }
                        maxi=max(maxi,val);
                    }
                }
                curr[j1][j2]=maxi;
            }
        }
        prev=curr;
    }

    return prev[0][m-1];
}

int main(){
    int rows,cols;
    cin>>rows>>cols;

    vector<vector<int>>grid(rows,vector<int>(cols));
       for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin >> grid[i][j];
        }
    }

    cout<<cherryPickup1(grid)<<endl;
    cout<<cherryPickup2(grid)<<endl;
    cout<<cherryPickup3(grid)<<endl;
    cout<<cherryPickup4(grid)<<endl;

        return 0;
}