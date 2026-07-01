#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& weights, int days,int cap){

    int daysR=1;
    int load=0;
    for(auto&it:weights){
        if(load+it>cap){
            daysR++;
            load=it;
        }else{
            load+=it;
        }
    }
    return daysR<=days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low=*max_element(weights.begin(),weights.end());
    int high=accumulate(weights.begin(),weights.end(),0);
    int ans=high;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(weights,days,mid)){
            ans=mid;
            high=mid-1;
        }else
           { low=mid+1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int days;
    cin >> days;

    int result = shipWithinDays(weights, days);
    cout << result << endl;

    return 0;
}