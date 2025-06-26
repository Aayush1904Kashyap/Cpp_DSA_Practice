#include <bits/stdc++.h>
using namespace std;

void leftRotate(int arr[],int n,int k){
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
    reverse(arr,arr+n);

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    // k=k%n;
    // int temp[k];
    // for(int i=0;i<k;i++){
    //     temp[i]=arr[i];
    // }
    // for(int i=k;i<n;i++){
    //     arr[i-k]=arr[i];
    // }
    // for(int i=0;i<n;i++){
    //     arr[n-k+i]=temp[i];
    // }

    leftRotate(arr,n,k);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}