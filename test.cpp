#include <bits/stdc++.h>
using namespace std;

struct Gate {
    int fromR, fromC;
    int toR, toC;
};

struct ProblemInput {
    int rows, cols;
    vector<vector<int>> grid;
    int startR, startC;
    int endR, endC;
    vector<Gate> gates;
    int maxTeleports;
};

static ProblemInput readInput() {
    ProblemInput in{};
    cin >> in.rows >> in.cols;

    in.grid.assign(in.rows, vector<int>(in.cols));
    for (int r = 0; r < in.rows; r++) {
        for (int c = 0; c < in.cols; c++) {
            cin >> in.grid[r][c];
        }
    }

    cin >> in.startR >> in.startC;
    cin >> in.endR >> in.endC;

    int numGates;
    cin >> numGates;
    in.gates.resize(numGates);

    for (int i = 0; i < numGates; i++) {
        cin >> in.gates[i].fromR >> in.gates[i].fromC
            >> in.gates[i].toR >> in.gates[i].toC;
    }

    cin >> in.maxTeleports;
    return in;
}

/*
 Return minimum steps from start -> end
 Each move costs 1
 Teleport also costs 1 and consumes one teleport charge
*/
int solve(int rows, int cols, const vector<vector<int>>& grid,
          int startR, int startC,
          int endR, int endC,
          const vector<Gate>& gates,
          int maxTeleports) {

    // map source cell -> destination(s)
    map<pair<int,int>, vector<pair<int,int>>> teleports;
    for (auto &g : gates) {
        teleports[{g.fromR, g.fromC}].push_back({g.toR, g.toC});
    }

    // dist[r][c][k] = min steps reaching cell with k teleports used
    const int INF = 1e9;
    vector<vector<vector<int>>> dist(
        rows,
        vector<vector<int>>(cols, vector<int>(maxTeleports + 1, INF))
    );

    queue<tuple<int,int,int>> q;   // r,c,used

    dist[startR][startC][0] = 0;
    q.push({startR, startC, 0});

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    while (!q.empty()) {
        tuple<int,int,int> cur = q.front();
q.pop();

int r = get<0>(cur);
int c = get<1>(cur);
int used = get<2>(cur);


        int steps = dist[r][c][used];

        // normal moves
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
            if (grid[nr][nc] == 1) continue;

            if (dist[nr][nc][used] > steps + 1) {
                dist[nr][nc][used] = steps + 1;
                q.push({nr, nc, used});
            }
        }

        // teleport moves
        if (used < maxTeleports && teleports.count({r,c})) {
            for (auto &dest : teleports[{r,c}]) {
                int nr = dest.first;
                int nc = dest.second;

                if (dist[nr][nc][used + 1] > steps + 1) {
                    dist[nr][nc][used + 1] = steps + 1;
                    q.push({nr, nc, used + 1});
                }
            }
        }
    }

    int ans = INF;
    for (int k = 0; k <= maxTeleports; k++) {
        ans = min(ans, dist[endR][endC][k]);
    }

    return (ans == INF ? -1 : ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ProblemInput in = readInput();

    int answer = solve(
        in.rows, in.cols, in.grid,
        in.startR, in.startC,
        in.endR, in.endC,
        in.gates,
        in.maxTeleports
    );

    cout << answer << '\n';
    return 0;
}

/*
================ input.txt TEST CASES ================

Test 1 (Basic Teleport)

3 4
0 0 1 0
0 1 1 0
0 0 0 0
0 0
2 3
1
0 1 2 2
1

Expected:
3


------------------------------------------------------

Test 2 (Multiple Gates)

3 5
0 0 0 0 0
1 1 1 1 0
0 0 0 0 0
0 0
2 4
2
0 1 0 3
0 2 2 1
2

Expected:
5


------------------------------------------------------

Test 3 (Resource Conservation)

3 4
0 0 0 0
0 1 1 0
0 0 0 0
0 0
2 3
1
0 0 2 0
1

Expected:
4


------------------------------------------------------

Test 4 (Unreachable)

3 3
0 1 0
1 1 1
0 1 0
0 0
2 2
0
0

Expected:
-1


------------------------------------------------------

Test 5 (Hidden edge case)

1 1
0
0 0
0 0
0
0

Expected:
0

======================================================
*/