#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag=false;

    bool containsKey(char ch) {
    return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root=new Node();
    }
    public:
    void insert(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    public:
    bool checkIfPrefixExists(string s){
        bool fl=true;
        Node* node=root;
        for(auto &it:s){
            if(node->containsKey(it)){
                node=node->get(it);
                if(node->isEnd()==false)
                    return false;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

string completeString(vector<string>& a) {
    int n=a.size();
    Trie trie;
    for(auto&it:a){
        trie.insert(it);
    }

    string longest="";
    for(auto&it:a){
        if(trie.checkIfPrefixExists(it)){
            if(it.length()>longest.length()){
                longest=it;
            }else if(it.length()==longest.length() && it<longest){
                longest =it;
            }
        }
    }    

    if(longest=="")return "None";
    return longest;

}

int main() {
    int n;
    cin >> n;

    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << completeString(nums) << endl;

    return 0;
}