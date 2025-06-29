class Solution {
public:
    int MOD = 1e9+7;
    int numSubseq(vector<int>& nums, int t) {
        sort(nums.begin(), nums.end());
        vector<int>pow2(nums.size()+1);
        pow2[0] = 1;
        for(int i = 1;i<pow2.size();i++){
            pow2[i] += (pow2[i-1]*2)%MOD;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int min = i, max = -1;
            int lo = i, hi = nums.size() - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[mid] <= t - nums[min]) {
                    max = mid;
                    lo = mid + 1;
                } else if (nums[mid] > t - nums[min]) {
                    hi = mid - 1;
                }
            }
            if (max == -1)
                break;
            ans += pow2[max-min]%MOD;
            ans %= (MOD);
        }
        return ans;
    }
};