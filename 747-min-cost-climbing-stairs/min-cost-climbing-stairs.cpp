class Solution {
public:
    int helper(vector<int>&cost,int idx,vector<int>&dp){
        if(idx<=1)return cost[idx];
        if(dp[idx] != -1)return dp[idx];
        return dp[idx] = cost[idx] + min(helper(cost,idx-1,dp),helper(cost,idx-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        int sum = 0;
        return min(helper(cost,n-1,dp),helper(cost,n-2,dp));
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        // for(int i = 2;i<n;i++){
        //     dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        // }
        // return min(dp[n-1],dp[n-2]);
    }
};