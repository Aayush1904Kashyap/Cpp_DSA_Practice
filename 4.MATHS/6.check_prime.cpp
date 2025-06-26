//prime number is that number which exactly have two factors---one and itself
#include <bits/stdc++.h>
using namespace std;

int checkPrime(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if(i!=n/i){
                cnt++;
            }
        }
    }
    if(cnt==2){
        return 1;
    }else return 0;
}
int main(){
    int n;
    cin>>n;
    if(checkPrime(n)){
    cout<<"PRIME NUMBER";
    }else{
    cout<<"NOT A PRIME NUMBER";
    }
}