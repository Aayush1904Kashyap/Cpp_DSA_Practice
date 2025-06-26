#include <bits/stdc++.h>
using namespace std;

void SortedinsertNum(stack<int>& st, int N) {
    if (st.empty() || st.top() <= N) {
        st.push(N);
        return;
    } else{
        int num=st.top();
        st.pop();
        SortedinsertNum(st, N);
        st.push(num);
    }
}

void SortStack(stack<int>&st){
    if(st.empty()){
        return;
    }
    else{
         int num = st.top();
    st.pop();

    SortStack(st);          
   SortedinsertNum(st, num);
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

    SortStack(s); 
    cout << "Stack after Sorting: ";
    printStack(s);

    return 0;
}
