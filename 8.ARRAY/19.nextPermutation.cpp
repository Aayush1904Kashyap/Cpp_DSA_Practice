//find breakpoint arr[i]<a[i+1]
//find greater than breakpoint but smallest one
//try other place in sorted order i.e reverse the remaining



#include <bits/stdc++.h>
using namespace std;
void reverse(int arr[], int start, int end) {
    while (start < end) {
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void permutation(int arr[], int n) {
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
     if (index == -1) {
        reverse(arr, 0, n - 1);
        return;
    }
    for(int i=n-1;i>=1;i--){
        if(arr[i]>arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }
    reverse(arr,index,n-1);
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    permutation(arr,n);
for (int i = 0; i < n; i++) {
        cout << arr[i]<<" ";
    }
    return 0;
}
