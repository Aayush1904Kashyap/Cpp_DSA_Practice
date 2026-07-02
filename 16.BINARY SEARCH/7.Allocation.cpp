/*Problem Statement

Given an array 'arr' of integer numbers, 'arr[i]' represents
the number of pages in the 'i-th' book.

There are 'm'number of students, and the task is to
allocate all the books to the students.

Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only
one student.
3. Book allocation should be in a
contiguous manner.

You have to allocate the book to 'm' students such that
the maximum number of pages assigned to a student is
minimum.

If the allocation of books is not possible, return -1.*/


// same problem as of SPLIT ARRAY AND PAINTERS PROBLEM


#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& arr, int pages){
    int s=1,pageStudent=0;
    for(auto& it:arr){
        if(pageStudent+it<=pages){
            pageStudent+=it;
        }else{
            s++;
            pageStudent=it;
        }
    }
    return s;
}

int findPages(vector<int>& arr, int m) {
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    int ans=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int cnt=f(arr,mid);
        if(cnt<=m){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;   // number of students
    cin >> m;

    int result = findPages(arr, m);
    cout << result << endl;

    return 0;
}