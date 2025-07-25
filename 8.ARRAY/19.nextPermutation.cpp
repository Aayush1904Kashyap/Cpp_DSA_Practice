#include <bits/stdc++.h>
using namespace std;

void reverseArr(int arr[], int start, int end) {
    while (start < end) swap(arr[start++], arr[end--]);
}

void nextPermutation(int arr[], int n) {
    int index = -1;
    
    // Step 1: find breakpoint
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            index = i;
            break;
        }
    }
    
    // If no breakpoint, reverse whole array
    if (index == -1) {
        reverseArr(arr, 0, n - 1);
        return;
    }
    
    // Step 2: find next greater element from right
    for (int i = n - 1; i > index; i--) {
        if (arr[i] > arr[index]) {
            swap(arr[i], arr[index]);
            break;
        }
    }
    
    // Step 3: reverse suffix after breakpoint
    reverseArr(arr, index + 1, n - 1);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    nextPermutation(arr, n);
    
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
