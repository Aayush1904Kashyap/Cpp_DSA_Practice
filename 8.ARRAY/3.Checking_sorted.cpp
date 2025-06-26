#include <bits/stdc++.h>
using namespace std;
int checkSorted(int arr[],int n){
   for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i+1]) {
            return 0; 
        }
    }
    return 1; 
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int c=checkSorted(arr,n);
    if(c==1){
        cout<<"THE ARRAY IS SORTED";
    }else if(c==0){
        cout<<"NOT SORTED ARRAY";
    }
    return 0;
}