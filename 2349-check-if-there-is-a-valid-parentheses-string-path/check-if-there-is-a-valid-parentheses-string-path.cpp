class Solution {
public:
    int n, m;
    int total;
    int dp[101][101][201]; // n , m , maximum no. of open brackets possible i.e total path length
    bool solve(int i, int j, vector<vector<char>>& g, int noo) {
        noo += (g[i][j] == '(' ? 1 : -1);
        if (noo < 0)
            return false;
        if (dp[i][j][noo] != -1)
            return dp[i][j][noo];
        if (i == n - 1 && j == m - 1) {
            return noo == 0;
        }
        if (i + 1 < n) {
            if (solve(i + 1, j, g, noo))
                return dp[i][j][noo] = true;
        }
        if (j + 1 < m) {
            if (solve(i, j + 1, g, noo))
                return dp[i][j][noo] = true;
        }
        return dp[i][j][noo] = false;
    }
    bool hasValidPath(vector<vector<char>>& g) {
        n = g.size();
        m = g[0].size();
        total = n + m - 1; // total length of any path
        if (total % 2 || g[0][0] == ')' || g[n - 1][m - 1] == '(')
            return false;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, g, 0);
    }
};