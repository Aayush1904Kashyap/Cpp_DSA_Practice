/*MAJORITY ELEMENT(>N/2 TIMES)
---MOORE'S VOTING ALGO---
*/



#include <bits/stdc++.h>
using namespace std;

int majority(int arr[], int n) {
    int cnt=0;
    int el;
    for(int i=0;i<n;i++){
        if(cnt==0){
            el=arr[i];
           
        } if(arr[i]==el){
            cnt++;
        }else{
            cnt--;
        }
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el)cnt1++;
    }
    if(cnt1>n/2){
        return el;
    }else return -1;

}

int main() {
     int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
  
    int result=majority(arr, n);

    if(result!=-1)
    {cout<<"ELEMENT HAVING MAJORITY IS "<<result<<" ";
    }else{
        cout<<"NO MAJOR ELEMENT";
    }
    

    return 0;
}
