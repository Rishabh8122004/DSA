class Solution {
public:
    long long solve(int i, int j, vector<vector<int>>& g, int k, int &n, int &m,vector<vector<vector<long long>>> &dp) {
        if (i == n || j == m) return INT_MIN;

        if (g[i][j] >= 1 && k == 0)
            return dp[i][j][k] = INT_MIN;

        if (i == n-1 && j == m-1) {
            if (g[i][j] >= 1) {
                if (k >= 1) return dp[i][j][k] = g[i][j];
                else return dp[i][j][k] = INT_MIN;
            }
            return dp[i][j][k] = g[i][j];
        }

        if (dp[i][j][k] != -2) return dp[i][j][k];

        int c = (g[i][j] >= 1 ? 1 : 0);
        int s = g[i][j];

        long long left = solve(i, j+1, g, k-c, n, m,dp);
        long long down = solve(i+1, j, g, k-c, n, m,dp);

        long long res = INT_MIN;

        if (left != INT_MIN)
            res = max(res, s + left);

        if (down != INT_MIN)
            res = max(res, s + down);

        return dp[i][j][k] = res;
    }

    int maxPathScore(vector<vector<int>>& g, int k) {
        int n = g.size(), m = g[0].size();
        vector<vector<vector<long long>>> dp(n,
    vector<vector<long long>>(m, vector<long long>(k+1, -2)));
        long long ans = solve(0, 0, g, k, n, m,dp);
        return ans < 0 ? -1 : ans;
    }
};