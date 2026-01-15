class Solution {
public:
    bool solve(int i, int bucketnum, int bucketsum,
               vector<int>& nums, vector<bool>& used,
               int reqsum, int k) {

        // 🎯 all buckets formed
        if (bucketnum == k) return true;

        // 🔁 bucket completed → start next bucket
        if (bucketsum == reqsum)
            return solve(0, bucketnum + 1, 0, nums, used, reqsum, k);

        for (int idx = i; idx < nums.size(); idx++) {

            if (used[idx]) continue;
            if (bucketsum + nums[idx] > reqsum) continue;

            used[idx] = true;
            if (solve(idx + 1, bucketnum, bucketsum + nums[idx],
                      nums, used, reqsum, k))
                return true;
            used[idx] = false;

            // 🔑 pruning (very important)
            if (bucketsum == 0) return false;
            if (bucketsum + nums[idx] == reqsum) return false;

            // avoid duplicates
            while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1])
                idx++;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % k != 0) return false;

        sort(nums.rbegin(), nums.rend());  // 🔑 early pruning
        if (nums[0] > sum / k) return false;

        vector<bool> used(nums.size(), false);
        return solve(0, 0, 0, nums, used, sum / k, k);
    }
};
