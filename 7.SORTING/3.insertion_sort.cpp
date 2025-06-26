/*algorithm:
takes an element and place it in its correct order
Step 1: [13, 46, 24, 52, 20, 9]
No swaps needed.

Step 2: [13, 46, 24, 52, 20, 9]
Swap 24 and 46.
Array: [13, 24, 46, 52, 20, 9]

Step 3: [13, 24, 46, 52, 20, 9]
No swaps needed.

Step 4: [13, 24, 46, 52, 20, 9]
Swap 20 and 52.
Array: [13, 24, 46, 20, 52, 9]
Swap 20 and 46.
Array: [13, 24, 20, 46, 52, 9]
Swap 20 and 24.
Array: [13, 20, 24, 46, 52, 9]


Step 5: [13, 20, 24, 46, 52, 9]
Swap 9 and 52.
Array: [13, 20, 24, 46, 9, 52]
Swap 9 and 46.
Array: [13, 20, 24, 9, 46, 52]
Swap 9 and 24.
Array: [13, 20, 9, 24, 46, 52]
Swap 9 and 20.
Array: [13, 9, 20, 24, 46, 52]
Swap 9 and 13.
Array: [9, 13, 20, 24, 46, 52]

Sorted array: [9, 13, 20, 24, 46, 52]
*/





#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int n){
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main(){
     int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    insertion_sort(arr,n);


    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
//TC----> O(n^2)--->worst case/average also
//        O(n)----->best case