class Solution {
public:
    bool solve(int start, int bucketNum, int currSum,
               vector<int>& nums, vector<bool>& used,
               int reqSum, int k) {

        // 🎯 all buckets formed
        if (bucketNum == k) return true;

        // 🔁 move to next bucket
        if (currSum == reqSum)
            return solve(0, bucketNum + 1, 0, nums, used, reqSum, k);

        for (int i = start; i < nums.size(); i++) {
            if (used[i]) continue;
            if (currSum + nums[i] > reqSum) continue;

            used[i] = true;
            if (solve(i + 1, bucketNum, currSum + nums[i],
                      nums, used, reqSum, k))
                return true;
            used[i] = false;

            // 🔑 PRUNING (very important)
            if (currSum == 0) return false;
            if (currSum + nums[i] == reqSum) return false;

            // skip duplicates
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % k != 0) return false;

        sort(nums.rbegin(), nums.rend());  // 🔑
        if (nums[0] > sum / k) return false;

        vector<bool> used(nums.size(), false);
        return solve(0, 0, 0, nums, used, sum / k, k);
    }
};
