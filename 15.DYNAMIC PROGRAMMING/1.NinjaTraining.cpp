/*Problem statement
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). 
Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. 
Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. 
Your task is to calculate the maximum number of merit points that Ninja can earn.*/

#include <bits/stdc++.h>
using namespace std;

int f(int day,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }

    if(dp[day][last]!=-1){
        return dp[day][last];
    }

    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            maxi=max(maxi,points[day][i]+f(day-1,i,points,dp));
        }
    }
    dp[day][last]=maxi;
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{   
    vector<vector<int>> dp(n,vector<int>(4,-1));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    dp[day][last]=max(dp[day][last],points[day][i]+dp[day-1][i]);

                }
            }

        }
    }
    return dp[n-1][3];
}

int ninjaTrainingSpace(int n, vector<vector<int>> &points)
{   
    vector<int> prev(4,-1);
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(points[0][0],max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++){
        vector<int> curr(4,-1);
        for(int last=0;last<4;last++){
            curr[last]=0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    curr[last]=max(curr[last],points[day][i]+prev[i]);
                }
            }
        }
        prev=curr;
    }
    return prev[3];
}


int main(){

    int n;
    cin>>n;
    vector<vector<int>> points(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>points[i][j];
        }
    }

    cout<<ninjaTraining(n, points)<<endl;
    cout<<ninjaTrainingSpace(n, points)<<endl;

    return 0;
}