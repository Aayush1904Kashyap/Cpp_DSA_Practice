#include<bits/stdc++.h>
using namespace std;

int removeDuplicate(int arr[], int n) {
    if (n == 0) return 0;

    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[i] != arr[j]) {
            arr[++i] = arr[j];
        }
    }
    return i + 1;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Sorting the array to ensure it works with the removeDuplicate function
    sort(arr, arr + n);

    int newSize = removeDuplicate(arr, n);

    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
