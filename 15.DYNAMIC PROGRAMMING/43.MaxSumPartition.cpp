#include <bits/stdc++.h>
using namespace std;

int f(int i,vector<int>& arr, int k){
    int n=arr.size();
    if(i==n)return 0;
    int maxSum=INT_MIN;
    int len=0;
    int maxi=INT_MIN;
    for(int j=i;j<min(n,k+i);j++){
        len++;
        maxi=max(maxi,arr[j]);
        int sum= len*maxi + f(j+1,arr,k);
        maxSum=max(sum,maxSum);
    }
    return maxSum;
}

// int maxSumAfterPartitioning(vector<int>& arr, int k) {
//     // code here
//     return f(0,arr,k);
// }

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n=arr.size();
    vector<int>dp(n+1,0);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
         int maxSum=INT_MIN;
    int len=0;
    int maxi=INT_MIN;
    for(int j=i;j<min(n,k+i);j++){
        len++;
        maxi=max(maxi,arr[j]);
        int sum= len*maxi + dp[j+1];
        maxSum=max(sum,maxSum);
    }
    dp[i]= maxSum;
    }
   return dp[0];
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout <<  maxSumAfterPartitioning(arr, k) << endl;

    return 0;
}