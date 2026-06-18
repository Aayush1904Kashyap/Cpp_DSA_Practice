#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n ? 0 : heights[i]);

            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> height(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> matrix(rows, vector<char>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = maximalRectangle(matrix);
    cout << result << endl;

    return 0;
}