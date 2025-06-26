/*
in this question

TC=O(4N)
SC=O(2N)

WHILE IN ORIGINAL 
TC=O(2N)
*/

#include <bits/stdc++.h>
using namespace std;

 vector<int> NGE(vector<int>& arr){
    int n=arr.size();
    vector<int> nge(n);
    stack<int>st;
    for(int i=2*n-1;i>=0;i--){
        while(!st.empty()&& st.top()<=arr[i%n]){
            st.pop();

        }
        if(i<n){
            nge[i]=st.empty()?-1:st.top();
        }
        st.push(arr[i%n]);
    }
    return nge;
 }


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = NGE(arr);
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}
