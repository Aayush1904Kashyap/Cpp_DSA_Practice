#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>&inputStack,int count,int size){

    if(count==size/2){
        inputStack.pop();
        return;
    }
    int num=inputStack.top();
    inputStack.pop();
    count++;
    solve(inputStack,count,size);
    inputStack.push(num);
};

void deleteMidElement(stack<int>&inputStack,int N)
{
    int count=0;
    solve(inputStack,count,N);

};

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<int> st;

    for (int i = 0; i < n; i++) {
        st.push(arr[i]);  
    }

    deleteMidElement(st, n);

    

    return 0;
}
