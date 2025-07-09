#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& arr, int k=3) {
        int n=arr.size();
        int lsum=0;
        int rsum=0;
        int maxsum=0;
        for(int i=0;i<k;i++){
            lsum=lsum+arr[i];
        }

        maxsum=lsum;
        int rindex=n-1;

        for(int i= k-1;i>=0;i--){
            lsum=lsum-arr[i];
            rsum=rsum+arr[rindex];
            rindex=rindex-1;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
    }

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    int result=maxScore(arr);
    cout<<"MAX SCORE IS: "<<result<<endl;
    

    return 0;
}
