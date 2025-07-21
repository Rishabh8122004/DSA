class Solution {
public:
    int solve(vector<int>&prices,int day,int &n,bool buy,vector<vector<int>>&dp,int& fee){
        if(day>=n)return 0;
        if(dp[day][buy] != INT_MIN)return dp[day][buy];
        int profit = INT_MIN;
        if(buy){
            int taken = solve(prices,day+1,n,false,dp,fee)-prices[day];
            int not_taken = solve(prices,day+1,n,true,dp,fee);
            profit =  max(profit,max(taken,not_taken));
        }
        else{
            int sold = solve(prices,day+1,n,true,dp,fee)+prices[day]-fee;
            int not_sold = solve(prices,day+1,n,false,dp,fee);
            profit = max(profit,max(sold,not_sold));
        }
        return dp[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n == 1)return 0;
        bool buy = true;
        vector<vector<int>>dp(50001,vector<int>(2,INT_MIN));
        return solve(prices,0,n,buy,dp,fee);
    }
};