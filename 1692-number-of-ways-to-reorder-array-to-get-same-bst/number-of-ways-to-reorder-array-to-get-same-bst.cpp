class Solution {
public:
    int n;
    long long binomial[1001][1001];
    long long mod = 1e9 + 7;
    long long solve_dfs(vector<int> v) {
        if (v.size() < 3) return 1;
        vector<int> left, right;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] < v[0])
                left.push_back(v[i]);
            else
                right.push_back(v[i]);
        }
        long long p = binomial[v.size() - 1][left.size()];
        long long left_ways = solve_dfs(left);
        long long right_ways = solve_dfs(right);
        return (((left_ways * right_ways) % mod) * p) % mod;
    }
    int numOfWays(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i <= n; i++) {
            binomial[i][0] = 1; // first column = 1
            binomial[i][i] = 1; // diagonal = 1
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                binomial[i][j] =
                    (binomial[i - 1][j - 1] + binomial[i - 1][j]) % mod;
            }
        }
        return (solve_dfs(nums) - 1)%mod;
    }
};