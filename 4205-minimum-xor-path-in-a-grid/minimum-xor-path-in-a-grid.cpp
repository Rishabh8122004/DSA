class Solution {
public:
    int minCost(vector<vector<int>>& g) {
        int n = g.size(),m = g[0].size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(1024, false)));
        dp[0][0][g[0][0]] = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0 && j == 0)continue;
                for(int k = 0;k<1024;k++){
                    if(j-1 >= 0){
                        dp[i][j][k ^ g[i][j]] = (dp[i][j-1][k] || dp[i][j][k ^ g[i][j]]);
                    }
                    if(i-1 >= 0){
                        dp[i][j][k ^ g[i][j]] = (dp[i-1][j][k] || dp[i][j][k ^ g[i][j]]);
                    }
                }
            }
        }
        for(int k = 0;k<1024;k++){
            if(dp[n-1][m-1][k] == true)return k;
        }
        return 0;
    }
};