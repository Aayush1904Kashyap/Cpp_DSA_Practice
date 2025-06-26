#include <bits/stdc++.h>
using namespace std;
int count(int n){
    int c=0;
    while(n>0){
        n=n/10;
        c++;
    }
    return c;
}
int checkarm(int n){
    int org =n;
    int arm=0;
    int digits= count(n);
    while(n>0){
        int r=n%10;
        arm=arm + pow(r,digits);
        n=n/10;
        
    }
    return arm;
}
int main(){
    int n;
    cin>>n;
    int arm=checkarm(n);
    if(n==arm){
    cout<<"TRUE";
}else{
    cout<<"FALSE";
}
}