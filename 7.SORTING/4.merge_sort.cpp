/*MERGE SORT-DIVIDE AND MERGE
Initial Array
Given array: [3,1,2,4,1,5,2,6,4]

Step 1: Divide the Array
First, we divide the array into two subarrays, one with 5 elements and the other with 4 elements.
First Division:
Left: [3,1,2,4,1]
Right: [5,2,6,4]

Step 2: Further Divide Each Subarray
We then further divide each of these subarrays. Starting with the left subarray [3,1,2,4,1].
Second Division (Left):
Left: [3,1,2]
Right: [4,1]

Next, we divide the right subarray [5,2,6,4].
Second Division (Right):
Left: [5,2]
Right: [6,4]

Step 3: Divide Again Until Single Element
Now, we further divide each of these subarrays until we have subarrays of single elements.
Third Division (Left of Left):
[3,1,2] becomes:
Left: [3,1]
Right: [2]

Third Division (Right of Left):
[4,1] becomes:
Left: [4]
Right: [1]

Third Division (Left of Right):
[5,2] becomes:
Left: [5]
Right: [2]

Third Division (Right of Right):
[6,4] becomes:
Left: [6]
Right: [4]
Now, we further divide [3,1].

Fourth Division (Left of Left of Left):
[3,1] becomes:
Left: [3]
Right: [1]

Step 4: Merge Sorted Subarrays
Now, we start merging the subarrays back together in sorted order.
First Merge:
Merge [3] and [1] to get [1,3]
Merge [1,3] and [2] to get [1,2,3]
Merge [4] and [1] to get [1,4]

Second Merge:
Merge [1,2,3] and [1,4] to get [1,1,2,3,4]

Third Merge:
Merge [5] and [2] to get [2,5]
Merge [6] and [4] to get [4,6]
Merge [2,5] and [4,6] to get [2,4,5,6]

Step 5: Final Merge
Finally, we merge the two sorted subarrays from the first division.
Final Merge:
Merge [1,1,2,3,4] and [2,4,5,6] to get the fully sorted array [1,1,2,2,3,4,4,5,6]

Summary
The Merge Sort algorithm follows a divide-and-conquer approach. Here's a summary of the steps:
Divide the array into subarrays recursively until each subarray has a single element.
Merge the subarrays back together in sorted order.
The intermediate steps for the given array [3,1,2,4,1,5,2,6,4] would be:

[3,1,2,4,1] and [5,2,6,4]
[3,1,2], [4,1], [5,2], and [6,4]
[3,1], [2], [4], [1], [5], [2], [6], and [4]
Merge to [1,3], [2], [1,4], [2,5], and [4,6]
Merge to [1,2,3], [1,4], [2,4,5,6]
Merge to [1,1,2,3,4] and [2,4,5,6]
Final merge to [1,1,2,2,3,4,4,5,6]

This process ensures that the array is sorted in O(n log n) time complexity, making Merge Sort an efficient sorting algorithm.
*/


#include<bits/stdc++.h>
using namespace std;



void merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1];  // Temporary array
    int left = low, right = mid + 1;
    int k = 0;

    // Merge the two halves [low...mid] and [mid+1...high]
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }

    // Copying left-out elements from left half
    while (left <= mid) {
        temp[k++] = arr[left++];
    }

    // Copying left-out elements from right half
    while (right <= high) {
        temp[k++] = arr[right++];
    }

    // Inserting from temp array to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;  // Calculate the mid point

        mergeSort(arr, low, mid);          // Recursively sort the first half
        mergeSort(arr, mid + 1, high);     // Recursively sort the second half
        merge(arr, low, mid, high);        // Merge the two sorted halves
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int arr[] = {1,0,1,0,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Unsorted array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
