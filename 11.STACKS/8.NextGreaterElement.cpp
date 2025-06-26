#include <bits/stdc++.h>
using namespace std;

 vector<int> NGE(vector<int>& arr){
    int n=arr.size();
    vector<int> nge(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&& st.top()<=arr[i]){
            st.pop();

        }
        if(st.empty()){
            nge[i]=-1;
        }else{
            nge[i]=st.top();
        }
        st.push(arr[i]);
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
        cout << val << " "<< endl;
    }
    
    return 0;
}
