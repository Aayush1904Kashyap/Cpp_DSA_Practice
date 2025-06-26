#include <bits/stdc++.h>
using namespace std;

void arrangeBySign(int arr[], int n) {
    vector<int>ans(n,0);
    int posIndex=0;
    int negIndex=1;
    for(int i=0;i<n;i++){
       if(arr[i]<0){
            ans[negIndex]=arr[i];
            negIndex+=2;
       }else{
            ans[posIndex]=arr[i];
            posIndex+=2;
       }

    }
     for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

 arrangeBySign(arr,n);

    for (int i = 0; i < n; i++) {
        cout << arr[i]<<" ";
    }

    return 0;
}
