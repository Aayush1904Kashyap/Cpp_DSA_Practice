#include <bits/stdc++.h>
using namespace std;

int stocks(int arr[], int n) {
   int mini=arr[0];
   int profit=0;
   for(int i=1;i<n;i++){
    int cost=arr[i]-mini;
    profit=max(profit,cost);
    mini=min(mini,arr[i]);
   } 
   return profit;
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int profit = stocks(arr, n);
    cout << "Maximum profit is " << profit << endl;

    return 0;
}
