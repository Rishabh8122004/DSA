class Solution {
public:
    // int helper(vector<int>&cost,int sum,int idx,vector<int>&dp){
    //     if(idx>=cost.size())return sum;
    //     if(dp[idx] != -1)return dp[idx];
    //     return dp[idx] = min(helper(cost,sum+cost[idx],idx+2,dp),helper(cost,sum+cost[idx],idx+1,dp));
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        // int sum = 0;
        // return min(helper(cost,sum,1,dp),helper(cost,sum,0,dp));
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};