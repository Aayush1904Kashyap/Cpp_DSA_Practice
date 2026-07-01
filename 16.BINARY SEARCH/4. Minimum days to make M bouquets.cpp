#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>arr,int day,int m,int k){
    int cnt=0;
    int bouq=0;
    for(auto&i:arr){
        if(i<=day){
            cnt++;
        }else{
            bouq+=(cnt/k);
            cnt=0;
        }
    }
    bouq+=(cnt/k);
    if( bouq>=m) return 1;
    return 0;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n=bloomDay.size();
    if(n<m*k)return -1;
    int low= *min_element(bloomDay.begin(),bloomDay.end());
    int high= *max_element(bloomDay.begin(),bloomDay.end());
    int ans=high;

    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(bloomDay,mid,m,k)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> bloomDay(n);
    for (int i = 0; i < n; i++) {
        cin >> bloomDay[i];
    }
    int m,k;
    cin >> m >> k;

    int result = minDays(bloomDay, m, k);
    cout << result << endl;

    return 0;
}