/*DEUTCH NATIONAL FLAG ALGORITHM
The Dutch National Flag algorithm works by maintaining three pointers: low, mid, and high. These pointers help in partitioning the array into four segments:

0 to low-1: elements that are 0.
low to mid-1: elements that are 1.
mid to high: elements that are yet to be sorted.
high+1 to n-1: elements that are 2.*/



#include <bits/stdc++.h>
using namespace std;

void sortZeroOnesTwo(int arr[], int n) {
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main() {
     int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
  
    sortZeroOnesTwo(arr, n);

   for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
