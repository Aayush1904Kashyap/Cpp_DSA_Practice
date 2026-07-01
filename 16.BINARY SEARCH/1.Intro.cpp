#include <bits/stdc++.h>
using namespace std;

int binarysearchIterative(vector<int>& nums,int target){
    int n=nums.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=low +(high-low)/2;
        if(nums[mid]==target)return mid;
        else if(nums[mid]<target)low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int helper(vector<int>& nums, int low, int high, int target) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (nums[mid] == target) return mid;
    if (nums[mid] < target) return helper(nums, mid + 1, high, target);

    return helper(nums, low, mid - 1, target);
}

int binarysearchRecursive(vector<int>& nums, int target) {
    return helper(nums, 0, nums.size() - 1, target);
}

//lower bound = smallest index of the target element such that nums[index]>=target
//upper bound = largest index of the target element such that nums[index]>target

int lowerBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = nums.size(); // Default to size of array if target is greater than all elements
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

//lb=lower_bound(arr.begin(),arr.end(),target)-arr.begin();


int upperBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = nums.size(); // Default to size of array if target is greater than all elements
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
//ub=upper_bound(arr.begin(),arr.end(),target)-arr.begin(); 


vector<int> binarySearchRange(vector<int>& nums, int target) {
    int first = lowerBound(nums, target);
    int last = upperBound(nums, target) - 1; // upperBound returns the index of the first element greater than target

    if (first <= last && first < nums.size() && nums[first] == target) {
        return {first, last};
    }
    return {-1, -1}; // Target not found
} 

int main(){
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<int> range = binarySearchRange(nums, 8);
    cout << range[0] << " " << range[1] << endl;

    cout<<binarysearchIterative(nums,10)<<endl;
    cout<<binarysearchRecursive(nums,10)<<endl;
    cout<<lowerBound(nums,5)<<endl;
    cout<<upperBound(nums,5)<<endl;
    

    return 0;
}