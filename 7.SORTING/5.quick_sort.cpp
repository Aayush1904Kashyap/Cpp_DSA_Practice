/*
QUICK SORT - DIVIDE AND CONQUER
Initial Array
Given array: [3,1,2,4,1,5,2,6,4]

Step 1: Choose a Pivot
First, we choose a pivot element from the array. For simplicity, we can choose the last element as the pivot.
Example:
Pivot: 4

Step 2: Partition the Array
Rearrange the array so that all elements less than the pivot are on the left, elements greater than the pivot are on the right.
Partitioned Array:
[3,1,2,1,2,4,5,6,4]

Step 3: Recursively Apply Quick Sort
Recursively apply the above steps to the subarrays formed by dividing the array at the pivot.
First Recursive Step:
Left Subarray: [3,1,2,1,2]
Right Subarray: [5,6,4]

Further Recursive Steps:
Partitioning [3,1,2,1,2] with pivot 2:
Left: [1,1,2]
Right: [3,2]

Partitioning [5,6,4] with pivot 4:
Left: []
Right: [5,6]

Continue partitioning until subarrays have single elements:
[1,1,2] -> No further partitioning needed
[3,2] -> Partition into [2] and [3]

Step 4: Combine the Results
Combine the results of the recursive steps to get the fully sorted array.
Final Sorted Array:
[1,1,2,2,3,4,4,5,6]

Summary
The Quick Sort algorithm follows a divide-and-conquer approach. Here's a summary of the steps:
Choose a pivot element from the array.
Partition the array such that elements less than the pivot are on the left, and elements greater than the pivot are on the right.
Recursively apply the above steps to the subarrays.
The intermediate steps for the given array [3,1,2,4,1,5,2,6,4] would be:

Choose pivot: 4
Partition to [3,1,2,1,2], 4, [5,6,4]
Partition [3,1,2,1,2] to [1,1,2], 2, [3,2]
Partition [5,6,4] to [], 4, [5,6]
Combine results to get [1,1,2,2,3,4,4,5,6]

This process ensures that the array is sorted in O(n log n) average time complexity, making Quick Sort an efficient sorting algorithm.
*/

#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = low - 1;  // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partitioning index

        quickSort(arr, low, pi - 1);  // Recursively sort the left subarray
        quickSort(arr, pi + 1, high); // Recursively sort the right subarray
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {3, 1, 2, 4, 1, 5, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
