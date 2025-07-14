class Solution {
public:
// TABULATION 
    //  int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    //    int m = grid.size(),n = grid[0].size();
    //    vector<vector<int>>dp(m,vector<int>(n,-1)); 
    //    for(int i = 0;i<m;i++){
    //     for(int j = 0;j<n;j++){
    //         if(grid[i][j] == 1)dp[i][j] = 0;
    //         else if(i == 0 || j == 0)dp[i][j] = 1;
    //         else dp[i][j] = (dp[i-1][j] + dp[i][j-1]);
    //     }
    //    }
    //    return dp[m-1][n-1];
    // }
// RECURSION + MEMOIZATION
    int helper(int curr_r,int curr_c,vector<vector<int>>&dp,vector<vector<int>>& grid){
        if(curr_r < 0 || curr_c < 0)return 0;
        if(grid[curr_r][curr_c] == 1){dp[curr_r][curr_c] = 0;return 0;}
        if(curr_r == 0 && curr_c == 0)return grid[0][0] == 1?0:1;
        if(dp[curr_r][curr_c] != -1)return dp[curr_r][curr_c];
        return dp[curr_r][curr_c] = helper(curr_r,curr_c-1,dp,grid)+helper(curr_r-1,curr_c,dp,grid);
    }
     int uniquePathsWithObstacles(vector<vector<int>>& grid){
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp,grid);
    }
};