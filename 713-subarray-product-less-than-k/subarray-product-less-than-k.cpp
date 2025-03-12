class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int i = 0, j = 0;
        long long prod = 0;
        int len, prev = -1;
        while (i < n) {
            prod = 1;
            while (prod < k && j < n) {
                prod *= nums[j];
                if (prod >= k)
                    break;
                j++;
            }
            j--;
            len = j - i + 1;
            if (j < prev) {
                    i = prev+1;
                    j = i;
                    continue;
                }
            if (prev != -1) {
                ans -= (((prev - i + 1) * (prev - i + 2)) / 2);
            }
            prev = j;
            ans += (((len) * (len + 1)) / 2);
            i++;
            j = i;
        }
        return ans;
    }
};