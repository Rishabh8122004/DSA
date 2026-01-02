class Solution {
public:
    bool solve(string &s, string &p, char st, int i, int j, vector<vector<int>> &dp) {
        if (i >= s.size() && j >= p.size()) return true;

        if (dp[i][j] != -1) return dp[i][j];

        if (i >= s.size()) {
            if (p[j] == '*' || (j < p.size() - 1 && p[j + 1] == '*'))
                return dp[i][j] = solve(s, p, p[j], i, j + 1, dp);
            return false;
        }

        if (i < s.size() && j >= p.size()) return false;

        if (s[i] != p[j]) {
            if (p[j] == '.') {
                if (j < p.size() - 1 && p[j + 1] == '*') {
                    return dp[i][j] =
                        (solve(s, p, p[j], i, j + 1, dp) ||
                         solve(s, p, st, i + 1, j, dp));
                } else {
                    return dp[i][j] = solve(s, p, p[j], i + 1, j + 1, dp);
                }
            }

            if (p[j] != '*' && p[j] != '.') {
                if (j < p.size() - 1 && p[j + 1] == '*')
                    return dp[i][j] = solve(s, p, p[j], i, j + 1, dp);
                return false;
            }

            if (p[j] == '*') {
                if (st == s[i] || st == '.') {
                    return dp[i][j] =
                        (solve(s, p, p[j], i, j + 1, dp) ||
                         solve(s, p, st, i + 1, j, dp));
                } else {
                    return dp[i][j] = solve(s, p, p[j], i, j + 1, dp);
                }
            }

            if (p[j] == '.') {
                return dp[i][j] = solve(s, p, p[j], i + 1, j + 1, dp);
            }
        }

        if (s[i] == p[j]) {
            if (j < p.size() - 1 && p[j + 1] == '*') {
                return dp[i][j] =
                    (solve(s, p, p[j], i, j + 1, dp) ||
                     solve(s, p, st, i + 1, j, dp));
            } else {
                return dp[i][j] = solve(s, p, p[j], i + 1, j + 1, dp);
            }
        }

        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(21, vector<int>(21, -1));
        char st = p[0];
        int i = 0, j = 0;
        return solve(s, p, st, i, j, dp);
    }
};
