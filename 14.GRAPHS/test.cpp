#include <bits/stdc++.h>
using namespace std;

int selectLeastResourceTasks(vector<int> resourceConsumption) {
    int n = resourceConsumption.size();
    // Use a set of (value, index) to get min efficiently
    set<pair<int,int>> s;
    vector<bool> removed(n, false);
    
    for (int i = 0; i < n; i++)
        s.insert({resourceConsumption[i], i});
    
    int total = 0;
    
    while (!s.empty()) {
        auto it = s.begin();
        int val = it->first;
        int idx = it->second;
        
        total += val;
        
        // Remove current
        s.erase(it);
        removed[idx] = true;
        
        // Remove left neighbor if exists and not already removed
        if (idx - 1 >= 0 && !removed[idx - 1]) {
            removed[idx - 1] = true;
            s.erase({resourceConsumption[idx - 1], idx - 1});
        }
        
        // Remove right neighbor if exists and not already removed
        if (idx + 1 < n && !removed[idx + 1]) {
            removed[idx + 1] = true;
            s.erase({resourceConsumption[idx + 1], idx + 1});
        }
    }
    
    return total;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> resourceConsumption(n);
    for (int i = 0; i < n; ++i) {
        cin >> resourceConsumption[i];
    }

    cout << selectLeastResourceTasks(resourceConsumption) << endl;

    return 0;
}