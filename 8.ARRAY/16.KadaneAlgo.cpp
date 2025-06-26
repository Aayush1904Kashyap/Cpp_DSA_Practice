#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n) {
    int sum = arr[0];
    int maxi = arr[0];

    for (int i = 1; i < n; i++) {
        sum = max(arr[i], sum + arr[i]);
        maxi = max(maxi, sum);
    }

    return maxi;
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    int maxSum = kadane(arr, n);
    cout << "Maximum sum of a subarray: " << maxSum << endl;

    return 0;
}
