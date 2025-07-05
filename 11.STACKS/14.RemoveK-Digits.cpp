#include <bits/stdc++.h>
using namespace std;

string removeKDigits(string & s,int k) {
    int n = s.length();
    stack<char> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && k>0 && (st.top() - '0')> (s[i]-'0') ){
            st.pop();
            k=k-1;
        }
        st.push(s[i]);
    }
    while(k>0) {
        st.pop();
        k--;
    }
    if(st.empty()){
        return "0";
    }
    string r="";
    while(!st.empty()){
        r=r+st.top();
        st.pop();
    }
    while(r.length()!=0 && r.back()=='0'){
        r.pop_back();
    }
    reverse(r.begin(), r.end()); 

    if(r.empty()) return "0";

    return r;
  

}


int main() {
    string s="1432219";
    int k=3;
string result = removeKDigits(s, k);
    cout << "Smallest possible number after removal: " << result << endl;

    return 0;
}
