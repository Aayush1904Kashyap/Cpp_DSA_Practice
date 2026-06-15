#include <bits/stdc++.h>
using namespace std;

bool check(string &s1 ,string &s2){
    if(s1.size() != s2.size()+1 ) return false;
    int f=0;
    int s=0;

    while(f<s1.size()){
        if(s<s2.size() && s1[f]==s2[s]){
            f++;
            s++;
        }else{
            f++;
        }
    }
     if(f==s1.size() && s==s2.size())return true;
     return false;
}

int longestStrChain(vector<string>& words) {
    int n=words.size();

    sort(words.begin(), words.end(), [](string s1, string s2) {
    return s1.size() < s2.size();
});
    vector<int>dp(n,1);

    int maxi=1;

    for(int i=0;i<n;++i){
        for(int prev=0;prev<i;++prev){
            if(check(words[i],words[prev]) && 1+dp[prev]>dp[i]){
                dp[i]=1+dp[prev];
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
        }
    }
    return maxi;
}

int main() {
    int n;
    cin >> n;         
    vector<string> words;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        words.push_back(s);
    }

    cout <<longestStrChain(words)<< endl;

    return 0;
}