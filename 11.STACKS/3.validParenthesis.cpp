#include <bits/stdc++.h>
using namespace std;



bool isValidParenthesis(string expression)
{
    stack<char> st;

        for(char ch : expression) {
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            else {
                if(st.empty()) return false;

                char top = st.top();
                if((ch == ')' && top == '(') ||
                   (ch == '}' && top == '{') ||
                   (ch == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
};

int main() {
    string s = "[{()}]";
      

    bool check=isValidParenthesis(s);

    if(check){
        cout<<"Valid"<<endl;
    }else{
        cout<<"invalid"<<endl;
    }


    

    return 0;
}
