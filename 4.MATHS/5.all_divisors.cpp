#include <bits/stdc++.h>
using namespace std;

void printDivisors(int n){
    vector<int> ls;
    //O(sqrt(n))
    for (int i = 1; i*i <=n; i++){
        if(n%i==0){
            ls.push_back(i);
            if(i!=n/i){
                ls.push_back(n/i);
            }
        }
    }
    sort(ls.begin(),ls.end());//-->sorting-------->O(no. of fact*log(no. of fact))
    for(auto it:ls){
        cout<<it<<" ";//-------->prints vector--------->O(no. of factors)
    }
}

int main(){
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//     if(n%i==0){
//         cout<<i<<" ";
//     }
// }
//above code has TC of O(n)

// int n;
//     cin >> n;
//     for (int i = 1; i <= sqrt(n); i++) {
//         if (n % i == 0) {
//             cout << i << " ";
//             if (i != n / i) {
//                 cout << n / i << " ";
//             }
//         }
//     }
//above code is optimized but not sorted

int n;
cin>>n;
printDivisors(n);
return 0;
}
