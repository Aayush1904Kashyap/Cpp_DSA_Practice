#include <bits/stdc++.h>
using namespace std;

int reverse(int n){
    int rev=0;
    while(n>0){
        int r=n%10;
        rev=rev*10 + r;
        n=n/10;
        
    }
    return rev;
}
int main(){
    int n;
    cin>>n;
    int rev=reverse(n);
    cout<<"reverse is  "<<rev;
}
