#include <bits/stdc++.h>
using namespace std;

vector<int> PSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        // strictly greater
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            pse[i] = st.top();
        }
        st.push(i);
    }

    return pse;
}

vector<int> NSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n, n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        // >= to handle equal elements to the right
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            nse[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return nse;
}

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse = PSE(arr);
    vector<int> nse = NSE(arr);
    long long sum = 0;
    int mod = 1e9 + 7;

    for (int i = 0; i < n; i++) {
        int left = i - pse[i];
        int right = nse[i] - i;
        sum = (sum + (1LL * arr[i] * left * right) % mod) % mod;
    }

    return (int)sum;
}

int main() {
     int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Sum of Subarray Minimums: " << sumSubarrayMins(arr) << endl;
    return 0;
}
