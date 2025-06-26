#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxi=0;
    for(int i=0;i<n;i++){
            if(arr[i]>arr[maxi]){
                maxi=i;
            }  
    }
    cout<<arr[maxi]<<" ";
    return 0;
}