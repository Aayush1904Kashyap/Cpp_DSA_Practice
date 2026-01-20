#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin() , arr.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int start =arr[i][0];
            int end =arr[i][1];

            if(!ans.empty() && end<=ans.back()[1]){
                continue;
            }
            for(int j=i+1 ; j<n; j++){
               if(arr[j][0]<=end){
                 end=max(arr[j][1],end);
               }else{
                break;
            }
            }
            ans.push_back({start,end});
        }

        return ans;

    }

    int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    vector<vector<int>> result = merge(arr);

    // Print merged intervals
    for (auto interval : result) {
        cout << interval[0] << " " << interval[1] << endl;
    }

    return 0;
}