class Solution {
public:
    bool solve(string &s, string &p,int i, int j, vector<vector<int>> &dp) {
        if (i >= s.size() && j >= p.size()) return dp[i][j] = true;

        if (dp[i][j] != -1) return dp[i][j];

        if (i >= s.size() && j<p.size()) {
            if (p[j] != '*') return dp[i][j] = false;
            return dp[i][j] = solve(s, p, i, j + 1, dp);
        }

        if (i < s.size() && j >= p.size()) return dp[i][j] = false;

        if (s[i] != p[j]) {
            if (p[j] == '?') {
                return dp[i][j] = solve(s, p, i + 1, j + 1, dp);
            }

            if (p[j] != '*' && p[j] != '?') {
                return dp[i][j] = false;
            }

            if (p[j] == '*') {
                if(j>0 && p[j-1] == '*')return dp[i][j] = solve(s,p,i,j+1,dp);
                return dp[i][j] = (solve(s,p,i+1,j,dp) || solve(s,p,i,j+1,dp));
            }
        }

        if (s[i] == p[j]) {
            return dp[i][j] = solve(s, p, i + 1, j + 1, dp);
        }
        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        int i = 0, j = 0;
        return solve(s, p, i, j, dp);
    }
};
