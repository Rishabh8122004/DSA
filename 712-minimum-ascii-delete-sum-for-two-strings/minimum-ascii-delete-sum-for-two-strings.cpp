class Solution {
public:
    int n,m;
    int solve(string &s1, string &s2,int i,int j,vector<vector<int>>&dp){
        if(i == n && j == m){return 0;}
        if(i==n && j<m){ return dp[i][j] = (int)s2[j]+solve(s1,s2,i,j+1,dp); }
        if(j==m && i<n){ return dp[i][j] = (int)s1[i]+solve(s1,s2,i+1,j,dp); }
        if(dp[i][j] != -1)return dp[i][j];
        if(s1[i] == s2[j])return dp[i][j] = solve(s1,s2,i+1,j+1,dp);
        return dp[i][j] = min((int)s1[i]+solve(s1,s2,i+1,j,dp),(int)s2[j]+solve(s1,s2,i,j+1,dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,0,0,dp);
    }
};