#include <bits/stdc++.h>
using namespace std;

 int atMost(vector<int>& nums, int k=3) {
        int left = 0, res = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2 == 1) --k;
            while (k < 0) {
                if (nums[left] % 2 == 1) ++k;
                ++left;
            }
            res += right - left + 1;
        }
        return res;
    }

int nicesubrrays(vector<int>& nums,int k=3) {
      return atMost(nums, k) - atMost(nums, k - 1);
    }



int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    int result=nicesubrrays(arr);
    cout<<"NO OF NICE SUBARRAYS ARE: "<<result<<endl;
    

    return 0;
}
