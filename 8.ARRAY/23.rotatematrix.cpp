#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &matrix, int n, int m) {
    int top = 0;
    int right = m - 1;
    int bottom = n - 1;
    int left = 0;

    vector<int> ans;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // Traverse from right to left, if there are remaining rows
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse from bottom to top, if there are remaining columns
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> ans = spiralMatrix(matrix, n, m);

    cout << "The Final matrix in spiral order is: \n";
    for (auto ele : ans) {
        cout << ele << " ";
    }
    cout << "\n";

    return 0;
}
