class Solution {
public:
// TABULATION 
    // int uniquePaths(int m, int n) {
    //     //tabulation method
    //    vector<vector<int>>dp(m,vector<int>(n,-1)); 
    //    for(int i = 0;i<m;i++){
    //     for(int j = 0;j<n;j++){
    //         if(i == 0 || j == 0)dp[i][j] = 1;
    //         else dp[i][j] = (dp[i-1][j] + dp[i][j-1]);
    //     }
    //    }
    //    return dp[m-1][n-1];
    // }
// RECURSION + MEMOIZATION
    int helper(int curr_r,int curr_c,vector<vector<int>>&dp){
        if(curr_r == 0 || curr_c == 0)return 1;
        if(dp[curr_r][curr_c] != -1)return dp[curr_r][curr_c];
        return dp[curr_r][curr_c] = helper(curr_r-1,curr_c,dp)+helper(curr_r,curr_c-1,dp);
    }
    int uniquePaths(int m, int n){
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp);
    }
};