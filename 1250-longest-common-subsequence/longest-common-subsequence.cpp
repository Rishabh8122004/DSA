class Solution {
public:
    int solve(string& a, string& b, int i, int j,vector<vector<int>>&dp) {
        if(i>=a.size() || j >= b.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans = 0;
        if(a[i] == b[j]){ans++;ans += solve(a,b,i+1,j+1,dp);}
        else ans += max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
        dp[i][j] = ans;
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        return solve(text1,text2,0,0,dp);
    }
};