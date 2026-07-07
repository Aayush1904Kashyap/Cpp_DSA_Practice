#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];

    Node() {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s) {
    Node* root = new Node();
    int cnt = 0;

    int n = s.size();

    // Insert every suffix
    for (int i = 0; i < n; i++) {
        Node* node = root;

        for (int j = i; j < n; j++) {

            if (!node->containsKey(s[j])) {
                node->put(s[j], new Node());
                cnt++;              // New substring found
            }

            node = node->get(s[j]);
        }
    }

    return cnt + 1;   // +1 for empty substring
}

// int countDistinctSubstrings(string s) {
//     unordered_set<string>st;
//     for(int i=0;i<s.length();++i){
//         string str="";
//         for(int j=i;j<s.length();j++){
//             str+=s[j];
//             st.insert(str);
//         }
//     } 
//     return st.size()+1; // plus one for empty string
// }

int main() {
    string s;
    cin >> s;

    cout << countDistinctSubstrings(s) << endl;

    return 0;
}