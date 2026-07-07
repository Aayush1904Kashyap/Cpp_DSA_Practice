#include <bits/stdc++.h>
using namespace std;

 struct Node {
        Node* links[2] = {NULL, NULL};

        bool containsKey(int bit) { return links[bit] != NULL; }

        Node* get(int bit) { return links[bit]; }

        void put(int bit, Node* node) { links[bit] = node; }
    };

class Trie {
public:
    Node* root;
    Trie() { 
        root = new Node();
    }
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num) {
        Node* node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxi |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxi;
    }
};


vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    sort(nums.begin(), nums.end());
    vector<pair<int, pair<int, int>>> offlineQueries;
    int q = queries.size();
    for(int i = 0; i < q; i++) {
        offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
    }
    sort(offlineQueries.begin(), offlineQueries.end());
    vector<int> ans(q,-1);
    int ind=0;
    Trie trie;
    for(int i = 0, j = 0; i < q; i++) {
        int ai = offlineQueries[i].first;
        int xi = offlineQueries[i].second.first;
        int qInd = offlineQueries[i].second.second;
        while(ind<nums.size() && nums[ind]<=ai) {
            trie.insert(nums[ind]);
            ind++;
        }
        if(ind!=0) {
            ans[qInd] = trie.getMax(xi);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> ans = maximizeXor(nums, queries);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}