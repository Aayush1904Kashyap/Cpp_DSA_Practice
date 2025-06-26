#include <bits/stdc++.h>
using namespace std;

vector<int> prefixMax(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixMax(n);
    prefixMax[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixMax[i] = max(prefixMax[i - 1], arr[i]);
    }
    return prefixMax;
}

vector<int> suffixMax(vector<int>& arr) {
    int n = arr.size();
    vector<int> suffixMax(n);
    suffixMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i + 1], arr[i]);
    }
    return suffixMax;
}




int trap(vector<int>& height){
    // int n=arr.size();
    // int total=0;
    // vector<int> prefix = prefixMax(arr);
    // vector<int> suffix = suffixMax(arr);

    // for(int i=0;i<n;i++){
    //     int leftMax=prefix[i];
    //     int rightmax=suffix[i];
    //     if(arr[i]<leftMax && arr[i]<rightmax){
    //         total+=min(leftMax,rightmax)-arr[i];
    //     }
    // }
    // return total;

    int n = height.size();
    if (n == 0) return 0;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int total = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            // process left side
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                total += leftMax - height[left];
            left++;
        } else {
            // process right side
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                total += rightMax - height[right];
            right--;
        }
    }

    return total;
   
 }


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result=trap(arr);
    cout<<"total water units trapped is: "<<result<<endl;
    
    return 0;
}
