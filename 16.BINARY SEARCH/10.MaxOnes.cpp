#include <bits/stdc++.h>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();
    int maxcnt=-1;
    int index=-1;
    for(int i=0;i<n;i++){
        int firstone=lower_bound(mat[i].begin(),mat[i].end(),1)-mat[i].begin();
        int cnt_ones=m-firstone;
        if(cnt_ones>maxcnt){
            maxcnt=cnt_ones;
            index=i;
        }

    }
    return {index,maxcnt};
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> result = rowAndMaximumOnes(mat);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}