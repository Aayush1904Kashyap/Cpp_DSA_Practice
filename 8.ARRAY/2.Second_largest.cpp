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
    int s_maxi=-1;//consider s_maxi=(-1) if all are positive if there is negative ones also then consider s_maxi=INT_MIN
    for(int i=0;i<n;i++){
        if(arr[i]>s_maxi && arr[i]!=arr[maxi]){
            s_maxi=arr[i];
        }
    }
    cout<<s_maxi<<" ";
    return 0;
}