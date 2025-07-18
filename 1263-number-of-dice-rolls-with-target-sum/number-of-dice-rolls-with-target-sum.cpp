class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int a = 1e9+7;
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=target;j++){
                int K = 1;
                while(K<=k){
                    if(j-K>=0)dp[i][j] += dp[i-1][j-K];
                    dp[i][j]%=a;
                    K++;
                }
            }
        }
        return dp[n][target];
    }
};