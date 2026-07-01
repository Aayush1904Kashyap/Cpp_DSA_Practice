#include <bits/stdc++.h>
using namespace std;
bool check(vector<int>& nums, int t,int d){
    int total=0;
    for(auto &it:nums){
        int val = (it + d - 1) / d;  //ceil(a/b)  →  (a+b-1)/b
        total+=val;
    }
    if(total<=t)return 1;
    return 0;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
    int ans=high;
    while(low<=high){
        int mid=low +(high-low)/2;
        if(check(nums,threshold,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int threshold;
    cin >> threshold;

    int result = smallestDivisor(nums, threshold);
    cout << result << endl;

    return 0;
}