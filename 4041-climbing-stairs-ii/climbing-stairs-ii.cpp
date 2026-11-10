class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        vector<int>dp(n+1,0);
        for(int i = 1;i<=n;i++){
            if(i-1 >= 0){
                dp[i] = (dp[i-1]+cost[i-1]+(i-(i-1))*(i-(i-1)));
            }
            if(i-2 >= 0){
                dp[i] = min(dp[i] , dp[i-2]+cost[i-1]+(i-(i-2))*(i-(i-2)));
            }
            if(i-3 >= 0){
                dp[i] = min(dp[i] , dp[i-3]+cost[i-1]+(i-(i-3))*(i-(i-3)));
            }
        }
        return dp[n];
    }
};