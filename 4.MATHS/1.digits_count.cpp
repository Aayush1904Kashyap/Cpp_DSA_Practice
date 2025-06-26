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
int main(){
    int n;
    cin>>n;
    int digits=count(n);
    cout<<"the number of digits are "<<digits;
}

//time compleximity is O(log10(n))
//if the number of iteration based on division then log TC comes into play
//say here division is by 10 hence base is 10 if division is by 5 then base will be 5