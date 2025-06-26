#include <bits/stdc++.h>
using namespace std;

int GCD(int n1,int n2){
//     int gcd=1;
//     int mini=min(n1,n2);
//     for(int i=1;i<=mini;i++){
//         if(n1%i==0&&n2%i==0){
//             gcd=i;
//         }
//     }
    while (n1 > 0 && n2 > 0) {
        if (n1 > n2)
            n1 = n1 % n2;
        else
            n2 = n2 % n1;
    }
    if (n1 == 0)
        return n2;
    return n1;
 }
int main(){
    int n1,n2;
    cin>>n1>>n2;;
    int gcd=GCD(n1,n2);
    cout<<"the GCD of "<<n1<<" and "<<n2<<" is "<<gcd;
}

//EUCLIDEAN ALGORITHM
//IF A>B THEN GCD(A,B)=GCD(A-B,B)
//GCD(A,B)=GCD(A%B,B)
//IF ONE NUMBER IS ZERO THEN OTHER IS ZERO
//TC is O(log(phi)(min(a,b)))