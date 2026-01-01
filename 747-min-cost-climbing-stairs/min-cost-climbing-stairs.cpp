class Solution {
public:
    int solve(vector<int>&dp,vector<int>&cost,int n){
        if(n <= 1)return 0;
        if(dp[n] != INT_MAX)return dp[n];
        dp[n] = 0;
        return dp[n]+=min(solve(dp,cost,n-1)+cost[n-1],solve(dp,cost,n-2)+cost[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(1001,INT_MAX);
        int n;
        n = cost.size();
        return solve(dp,cost,n);
    }
};