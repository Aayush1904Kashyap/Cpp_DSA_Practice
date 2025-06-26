#include <bits/stdc++.h>
using namespace std;

bool hasRedundantBrackets(string s)
{
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } 
        else if (ch == ')') {
            bool isRedundant = true;

            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false;
                }
                st.pop();
            }

            if (!st.empty()) st.pop(); // Pop the '('

            if (isRedundant) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    string s = "((a+b))";

    if (hasRedundantBrackets(s)) {
        cout << "Redundant" << endl;
    } else {
        cout << "Not Redundant" << endl;
    }

    return 0;
}
