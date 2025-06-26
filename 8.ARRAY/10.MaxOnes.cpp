#include <bits/stdc++.h>
using namespace std;

int maxOnes(int arr[], int n) {
   int maxi=0;
   int count=0;
   for(int i=0;i<n;i++){
    if(arr[i]==1){
        count=count+1;
        maxi=max(maxi,count);
    }else if(arr[i]==0){
        count=0;

    }
   }
   return maxi;

}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = maxOnes(arr, n);
    
     cout << "Max number of consecutive ones are " << result << endl;
    
    return 0;
}
