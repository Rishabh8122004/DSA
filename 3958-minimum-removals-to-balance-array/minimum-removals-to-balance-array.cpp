class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = n;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] <= (long long)nums[i] * k)
                j++;

            int window = j - i;
            ans = min(ans, n - window);
        }
        return ans;
    }
};
