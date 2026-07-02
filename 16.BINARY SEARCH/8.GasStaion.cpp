#include <bits/stdc++.h>
using namespace std;

// long double minimiseMaxDistance(vector<int>& arr, int k) {
//     int n=arr.size();
//     vector<int>howmany(n-1,0);
//     priority_queue<pair<long double,int>>pq;
//     for(int i=0;i<n-1;i++){
//         pq.push({arr[i+1]-arr[i],i});
//     }

//     for(int gas=1;gas<=k;gas++){
//         auto tp=pq.top();
//         pq.pop();
//         int secIndex=tp.second;
//         howmany[secIndex]++;
//         long double initial=arr[secIndex+1]-arr[secIndex];
//         long double newSecLen=initial/(long double)(howmany[secIndex]+1);
//         pq.push({newSecLen,secIndex});
//     }
//     return pq.top().first;
// }

    int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
        int n = arr.size();
        int cnt = 0;

        for (int i = 1; i < n; i++) {
            int numberInBetween = (arr[i] - arr[i - 1]) / dist;

            if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
                numberInBetween--;
            }
            cnt += numberInBetween;
        }
        return cnt;
    }

    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        long double low = 0, high = 0;
        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }
        long double diff = 1e-6;
        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, arr);
            if (cnt > k) low = mid;
            else high = mid;
        }

        return high;
    }


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;   // new gas stations
    cin >> k;

    long double result = minimiseMaxDistance(arr, k);
    cout << fixed << setprecision(6) << result << endl;

    return 0;
}