class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    void solve(vector<vector<int>>& g, int i, int j,
               vector<vector<vector<long long>>>& dp,
               vector<vector<bool>>& vis) {
        int m = g.size(), n = g[0].size();

        if (vis[i][j]) return;
        vis[i][j] = true;

        if (i == m - 1 && j == n - 1) {
            dp[i][j][0] = g[i][j]; // max
            dp[i][j][1] = g[i][j]; // min
            return;
        }

        long long curMax = LLONG_MIN;
        long long curMin = LLONG_MAX;
        long long val = g[i][j];

        if (i + 1 < m) {
            solve(g, i + 1, j, dp, vis);

            long long a = val * dp[i + 1][j][0];
            long long b = val * dp[i + 1][j][1];

            curMax = max(curMax, max(a, b));
            curMin = min(curMin, min(a, b));
        }

        if (j + 1 < n) {
            solve(g, i, j + 1, dp, vis);

            long long a = val * dp[i][j + 1][0];
            long long b = val * dp[i][j + 1][1];

            curMax = max(curMax, max(a, b));
            curMin = min(curMin, min(a, b));
        }

        dp[i][j][0] = curMax; // max product from (i,j) to end
        dp[i][j][1] = curMin; // min product from (i,j) to end
    }

    int maxProductPath(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();

        vector<vector<vector<long long>>> dp(
            m, vector<vector<long long>>(n, vector<long long>(2, 0))
        );
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        solve(g, 0, 0, dp, vis);

        long long ans = dp[0][0][0];
        if (ans < 0) return -1;
        return (int)(ans % MOD);
    }
};