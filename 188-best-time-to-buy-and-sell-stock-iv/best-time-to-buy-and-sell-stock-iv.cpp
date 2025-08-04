class Solution {
public:
    int solve(vector<int>&p,int i,int k,bool buy,vector<vector<vector<int>>>&dp){
        if(k == 0 || i>=p.size())return 0;
        if(dp[i][k][buy] != INT_MIN)return dp[i][k][buy];
        int ans = 0;
        if(buy && k>0){
            ans += max(solve(p,i+1,k,false,dp)-p[i],solve(p,i+1,k,true,dp));
        }
        if(!buy){
            ans += max(solve(p,i+1,k-1,true,dp)+p[i],solve(p,i+1,k,false,dp));
        }
        dp[i][k][buy] = ans;
        return ans;
    }
    int maxProfit(int k, vector<int>& p) {
        vector<vector<vector<int>>>dp(p.size()+1,vector<vector<int>>(k+1,vector<int>(2,INT_MIN)));
        return solve(p,0,k,true,dp);
    }
};