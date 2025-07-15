class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i == 0 && j == 0){return grid[0][0];}
        if(dp[i][j] != -1)return dp[i][j];
        if(i == 0 || j == 0){
            if(i == 0) return dp[i][j] = grid[i][j]+helper(i,j-1,grid,dp);
            else if(j == 0) return dp[i][j] = grid[i][j]+helper(i-1,j,grid,dp);
        }
        return dp[i][j] = grid[i][j]+min(helper(i-1,j,grid,dp),helper(i,j-1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,grid,dp);
    }
};