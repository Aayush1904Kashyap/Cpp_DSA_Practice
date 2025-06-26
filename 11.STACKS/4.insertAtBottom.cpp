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

    insertNum(s, 10); 
    cout << "Stack after inserting at bottom: ";
    printStack(s);

    return 0;
}
