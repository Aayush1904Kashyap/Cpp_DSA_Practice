#include <bits/stdc++.h>
using namespace std;

void insertNum(stack<int>& st, int N) {
    if (st.empty()) {
        st.push(N);
    } else {
        int num = st.top();
        st.pop();
        insertNum(st, N);
        st.push(num);
    }
}

void reverseStack(stack<int>&st){
    if(st.empty()){
        return;
    }
    else{
        int num=st.top();
        st.pop();
        reverseStack(st);
        insertNum(st,num);
    }
}





void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<int> s;

    for (int i = 0; i < n; i++) {
        s.push(arr[i]);  
    }

    reverseStack(s); 
    cout << "Stack after reversing: ";
    printStack(s);

    return 0;
}
