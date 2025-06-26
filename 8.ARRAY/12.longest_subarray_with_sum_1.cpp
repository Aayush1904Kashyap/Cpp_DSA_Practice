#include <bits/stdc++.h>
using namespace std;

int longestSubarraywithSumk(vector<int> a, long long k) {
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxlen = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        if (sum == k) {
            maxlen = max(maxlen, i + 1);
        }
        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxlen = max(maxlen, len); 
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    return maxlen;
}}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long k;
    cin >> k;

    int result = longestSubarraywithSumk(arr, k);

    cout << result << endl;

    return 0;
}
