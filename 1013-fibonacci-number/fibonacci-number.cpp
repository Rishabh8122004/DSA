class Solution {
public:
 // recursion + memoisation method
    // int solve(int n,vector<int>&dp){
    //     if(dp[n] != -1)return dp[n];
    //     return dp[n] = solve(n-1,dp)+solve(n-2,dp);;
    // }
    // int fib(int n) {
    //     if(n == 0)return 0;
    //     vector<int>dp(n+1,-1);
    //     dp[1] = 1;dp[0] = 0;
    //     solve(n,dp);
    //     return solve(n,dp);;
    // }
    // tabulation or iterative method;
    int fib(int n) {
        if(n == 0)return 0;
        vector<int>dp(n+1,0);
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};