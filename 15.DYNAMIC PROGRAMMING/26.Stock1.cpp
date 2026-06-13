#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
      int n=prices.size();
      int mini=prices[0],profit=0;
      for(int i=1;i<n;++i){
        int cost=prices[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,prices[i]);
      }  
      return profit;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<maxProfit(arr)<<endl;
}