#include <bits/stdc++.h>
using namespace std;

 bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

// int f(int i,string s){
//     int n=s.length();
//     string temp="";
//     int minCost=INT_MAX;
//     if(i==n) return 0;
//     for(int j=i;j<n;++j){
//         temp+=s[j];
//         if(isPalindrome(temp)){
//             int cost=1+f(j+1,s);
//             minCost=min(minCost,cost);
//         }
//     }
//     return minCost;
// }

int minCut(string s) {
    int n=s.length();
    
    
    vector<int>dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        int minCost=INT_MAX;
        string temp="";
       for(int j=i;j<n;++j){
        if(isPalindrome(s,i,j)){
            int cost=1+dp[j+1];
            minCost=min(minCost,cost);
        }
        } 
        dp[i]=minCost;
    }
        return dp[0]-1;
}



int main() {
    string s;
    cin >> s;

    cout <<minCut(s) << endl;

    return 0;
}