class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>>& dp) {
        // base cases
        if (i == a.size()) return b.size() - j;
        if (j == b.size()) return a.size() - i;

        if (dp[i][j] != -1) return dp[i][j];

        // if characters match, no operation needed
        if (a[i] == b[j]) {
            return dp[i][j] = solve(a, b, i + 1, j + 1, dp);
        }

        // operations: insert, delete, replace
        int insertOp  = solve(a, b, i, j + 1, dp);
        int deleteOp  = solve(a, b, i + 1, j, dp);
        int replaceOp = solve(a, b, i + 1, j + 1, dp);

        return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string a, string b) {
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, -1));
        return solve(a, b, 0, 0, dp);
    }
};
