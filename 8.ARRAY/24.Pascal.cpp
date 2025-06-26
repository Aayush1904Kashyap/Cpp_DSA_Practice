#include <iostream>
#include <vector>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // Calculate nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return static_cast<int>(res);
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    // Store the entire Pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // Temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

int main() {
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (const auto& row : ans) {
        for (const auto& ele : row) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
