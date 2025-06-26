//hashing is prestore and fetching the value when required
//in case of integer hash arr;
//inside main------->max size is near about 10^6----->if bool then 10^7
//while as global--->max size is near about 10^7----->if bool then 10^8


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //precompute
    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        //fetch
        cout<<hash[number]<<endl;
    }
    
    return 0;
}
