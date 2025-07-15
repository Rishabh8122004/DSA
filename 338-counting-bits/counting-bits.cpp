class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0)return {0};
        if(n == 1)return {0,1};
        vector<int>dp(n+1,1); // every number has at least 1 set bit except 0
        dp[0] = 0; // 0 has no set bit
        for(int i = 2;i<=n;i++){
        dp[i] += dp[i&(i-1)]; 
        }
        return dp;
    }
};