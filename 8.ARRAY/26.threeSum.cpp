#include <bits/stdc++.h>
using namespace std;

int* twoSum(int arr[], int n, int k) {
    static int result[2];
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == k) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return nullptr;
}

int main() {
     int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int* result = twoSum(arr, n, k);

    if(result != nullptr) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No pair found." << endl;
    }

    return 0;
}
