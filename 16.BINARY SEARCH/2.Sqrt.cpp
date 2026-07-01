#include <bits/stdc++.h>
using namespace std;

int sqrt(int x){
    int low=0,high=x;
    int ans= 1;
    while(low<=high){
        long long mid=low+(high-low)/2;
        if(1ll*mid*mid<=x){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}


int mypow(long long base, int n, int x) {
    // return 1 if calculated value == x
    // return 0 if calculated value < x
    // return 2 if calculated value > x

    long long ans = 1;

    for (int i = 1; i <= n; i++) {
        ans *= base;

        if (ans > x) return 2;
    }

    if (ans == x) return 1;
    return 0;
}

int nthRoot(int x, int n) {
    int low = 1, high = x;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int res = mypow(mid, n, x);

        if (res == 1) {
            return mid;
        }
        else if (res == 0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main(){
    int x;
    cin>>x;
    int n;
    cin>>n;
    cout<<sqrt(x)<<endl;
    cout<<nthRoot(x,n)<<endl;
    return 0;
}