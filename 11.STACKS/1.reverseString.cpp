#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "malayalam";
    string rev = "";
    stack<char> st;  

    for (int i = 0; i < s.length(); i++) {
        st.push(s[i]);  
    }

    while (!st.empty()) {
        rev += st.top();  
        st.pop();         
    }

    cout << "Reversed string: " << rev << endl;

    return 0;
}
