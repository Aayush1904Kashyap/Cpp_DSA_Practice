/*algorithm
select minimum and swap 
eg:unsorted array: 13 46 24 52 20 9
    step1-9 46 24 52 20 13
    step2-9 13 24 52 20 46
    step3-9 13 20 52 24 46
    step4-9 13 20 24 52 46
    step5-9 13 20 24 46 52

Outer Loop (i from 0 to n-1):
Sets the starting index of the range to i.
Range is initially the whole array and shrinks with each iteration.

Inner Loop (j from i to n-1):
Finds the minimum element in the range [i...n-1].

Swap:
Swap the found minimum element with the first element of the current range (i-th element).

Repeat:
Increment i and repeat until the entire array is sorted.

After each iteration, the array is sorted up to index i

    TC::  O(n(n+1)/2)==O(n^2)--->best/worst/average
*/


#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minn=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[i]){
                minn=j;
            }
        }
        int temp=arr[minn];
        arr[minn]=arr[i];
        arr[i]=temp;
    }
}

int main(){
     int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    selection_sort(arr,n);


    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}