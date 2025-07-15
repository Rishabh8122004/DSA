class Solution {
public:
    int anding(int x,int y,vector<int>&dp){
        if(dp[x]!=-1)return dp[x];
        return dp[x] = 1+anding(x&y,(x&y)-1,dp);
    }
    vector<int> countBits(int n) {
        if(n == 0)return {0};
        if(n == 1)return {0,1};
        vector<int>dp(n+1,-1);
        dp[1] = 1;dp[0] = 0;
        for(int i = 2;i<=n;i++){
        dp[i] = anding(i,i-1,dp);
        }
        return dp;
    }
};