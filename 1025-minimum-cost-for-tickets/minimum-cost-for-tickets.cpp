class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i, vector<int>& dp) {
        if(i >= days.size()) return 0;
        if(dp[i] != -1) return dp[i];

        // Option 1: Buy 1-day pass
        int one_day = costs[0] + solve(days, costs, i+1, dp);

        // Option 2: Buy 7-day pass
        int j = i;
        while(j < days.size() && days[j] <= days[i]+6) j++;
        int seven_day = costs[1] + solve(days, costs, j, dp);

        // Option 3: Buy 30-day pass
        j = i;
        while(j < days.size() && days[j] <= days[i]+29) j++;
        int thirty_day = costs[2] + solve(days, costs, j, dp);

        return dp[i] = min({one_day, seven_day, thirty_day});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return solve(days, costs, 0, dp);
    }
};
