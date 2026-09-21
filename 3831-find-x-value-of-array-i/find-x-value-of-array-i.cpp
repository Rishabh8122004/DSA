class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        int n = nums.size();

        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int i = 0; i < n; i++) {

            vector<long long> ndp(k, 0);

            // Start a new subarray with nums[i]
            int r = nums[i] % k;
            ndp[r]++;

            // Extend every subarray ending at i-1
            for (long long j = 0; j < k; j++) {

                if (dp[j] == 0)
                    continue;

                int nr = (j * nums[i]) % k;

                ndp[nr] += dp[j];
            }

            // Add all subarrays ending at i to answer
            for (int j = 0; j < k; j++)
                result[j] += ndp[j];

            dp = ndp;
        }

        return result;
    }
};