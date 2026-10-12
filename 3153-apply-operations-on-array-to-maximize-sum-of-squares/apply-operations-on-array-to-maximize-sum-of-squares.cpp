class Solution {
public:
    int mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> cnt(32);
        for (int x : nums) {
            for (int b = 0; b < 32; b++) {
                if (x & (1 << b))
                    cnt[b]++;
            }
        }
        int ans = 0;
        while (k--) {
            long long x = 0;
            for (int b = 0; b < 32; b++) {
                if (cnt[b]) {
                    cnt[b]--;
                    x += (pow(2, b));
                }
            }
            if (x == 0)
                break;
            ans = (ans + (x * x) % mod) % mod;
        }
        return ans;
    }
};