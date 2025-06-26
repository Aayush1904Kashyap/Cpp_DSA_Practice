#include<bits/stdc++.h>
using namespace std;


void print(int i,int n){
    if(i<n)return;
    cout<<i<<endl;
    print(i-1,n);
    
}

int main(){
    int n;
    cin>>n;
    print(n,1);
    return 0;
} 

//tc=o(n)
//sc=o(n)