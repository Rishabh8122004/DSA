class Solution {
public:
    int v[505][505];
    int n, m;

    bool solve(vector<vector<char>>& g, int i, int j, int pi, int pj, char ch) {
        v[i][j] = 1;

        // right
        if (j + 1 < m && g[i][j + 1] == ch) {
            if (v[i][j + 1] == 0) {
                if (solve(g, i, j + 1, i, j, ch)) return true;
            } else if (j + 1 != pj) return true;
        }

        // down
        if (i + 1 < n && g[i + 1][j] == ch) {
            if (v[i + 1][j] == 0) {
                if (solve(g, i + 1, j, i, j, ch)) return true;
            } else if (i + 1 != pi) return true;
        }

        // left
        if (j > 0 && g[i][j - 1] == ch) {
            if (v[i][j - 1] == 0) {
                if (solve(g, i, j - 1, i, j, ch)) return true;
            } else if (j - 1 != pj) return true;
        }

        // up
        if (i > 0 && g[i - 1][j] == ch) {
            if (v[i - 1][j] == 0) {
                if (solve(g, i - 1, j, i, j, ch)) return true;
            } else if (i - 1 != pi) return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& g) {
        memset(v, 0, sizeof(v));
        n = g.size();
        m = g[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 0) {
                    if (solve(g, i, j, -1, -1, g[i][j])) return true;
                }
            }
        }
        return false;
    }
};