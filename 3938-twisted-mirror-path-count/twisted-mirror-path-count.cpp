class Solution {
public:
    int mod = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int dp[n + 1][m + 1][2];
        memset(dp, 0, sizeof(dp));
        int right = 0 , down = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0){
                    dp[i][j][down] = 1; // 1 for down (Starting direction)
                    dp[i][j][right] = 1; // 0 for right (Starting direction)
                }
                else if (i == 0) {
                    if(g[i][j] == 1) // if grid cell is a mirror cell
                        dp[i][j][down] += dp[i][j-1][right]; // taking from right and sending to down if it is a mirror cell
                    else{
                        dp[i][j][right] += dp[i][j-1][right]; // Normal straight move right
                        dp[i][j][down] += dp[i][j-1][right];
                    }
                }
                else if (j == 0){
                    if(g[i][j] == 1) // if grid cell is a mirror cell
                        dp[i][j][right] += dp[i-1][j][down]; // Upar se aakar right turn liya
                    else{
                        dp[i][j][right] += dp[i-1][j][down];
                        dp[i][j][down] += dp[i-1][j][down]; // Normal straight move down
                    }
                }
                else{
                    if(g[i][j] == 1){ // if grid cell is a mirror cell
                        dp[i][j][right] += dp[i-1][j][down]; // Mirror reflection from up to right
                        dp[i][j][down] += dp[i][j-1][right]; // Mirror reflection from left to down
                    }
                    else{ // Empty cell: dono directions pass through hongi
                        dp[i][j][right] += (dp[i-1][j][down] + dp[i][j-1][right])%mod;
                        dp[i][j][down] += (dp[i-1][j][down] + dp[i][j-1][right])%mod;
                    }
                }
            }
        }
        return dp[n-1][m-1][right]; // Destination par right state ka result return
    }
};