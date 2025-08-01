class Solution {
public:
    int numTrees(int n) {
        if(n<3)return n;
        vector<int>dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i<=n;i++){
            for(int k = 1;k<=i;k++){
                dp[i] += (dp[k-1]*dp[i-k]);
            }
        }
        return dp[n];
    }
};