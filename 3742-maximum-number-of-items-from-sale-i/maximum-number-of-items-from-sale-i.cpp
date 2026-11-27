class Solution {
public:
    int n;
    vector<int> free_items; // factor with free items for first purchase
    int dp[1001][1501];
    int mn = 1500; // minimum price in the items for the base case
    int knapsack(vector<vector<int>>& it, int i, int b) {
        if (i == n)
            return b / mn; // using leftover b to gain as much item as we can
        if (dp[i][b] != -1)
            return dp[i][b];
        int take = 0, leave = 0;
        if (it[i][1] <= b) {
            take = knapsack(it, i + 1, b - it[i][1]) + free_items[i];
        }
        leave = knapsack(it, i + 1, b);
        return dp[i][b] = max(take, leave);
    }
    int maximumSaleItems(vector<vector<int>>& it, int b) {
        n = it.size();
        memset(dp, -1, sizeof(dp));
        free_items.resize(n, 0);
        unordered_map<int, int> mp; // item factor and no. of items
        int mx = it[0][0];          // item with maximum factor
        for (int i = 0; i < it.size(); i++) {
            mp[it[i][0]]++;
            mx = max(mx, it[i][0]);
            mn = min(mn, it[i][1]);
        }
        for (int i = 0; i < it.size(); i++) {
            int x = it[i][0];
            while (x <= mx) {
                free_items[i] += mp[x]; // adding all the items equal to x (i.e. a multiple of it[i][0])
                x += it[i][0];
            }
        }
        return knapsack(it, 0, b);
    }
};