#include <bits/stdc++.h>
using namespace std;

vector<string> getSubsequences(string s) {
        int n = s.size();
        int total = 1 << n;
        vector<string> subsequences;
        for (int mask = 0; mask < total; mask++) {
            string subseq = "";
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subseq += s[i];
                }
            }
            subsequences.push_back(subseq);
        }
        return subsequences;
    }


int main() {
    string s = "abc";
    vector<string> subsequences = getSubsequences(s);
    for (auto &subseq : subsequences) {
        cout << "\"" << subseq << "\"" << endl;
    }
    return 0;
}
