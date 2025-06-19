class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> flag(n, true);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (!flag[i])
                continue;
            flag[i] = false;
            vector<int> v;
            int limit = nums[i] + k;
            for (int j = i + 1; j < n; j++) {
                if (!flag[j])
                    continue;
                if (nums[j] <= limit && nums[j] >= nums[i]) {
                    v.push_back(nums[i]);
                    flag[j] = false;
                }
                else break;
            }
            ans.push_back(v);
        }
        return ans.size();
    }
};