#include <bits/stdc++.h>
using namespace std;

int missingNum(int arr[], int n) {
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    int nsum=((n+2)*(n+1))/2;
    return nsum-sum;

}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = missingNum(arr, n);
    
     cout << "Missing Number from 1 to n is " << result << endl;
    
    return 0;
}
