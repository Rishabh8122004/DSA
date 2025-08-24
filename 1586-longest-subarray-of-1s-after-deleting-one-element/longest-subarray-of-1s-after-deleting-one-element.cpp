class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int curr_start = 0, next_start = 0;
        int zero = 0;
        int ans = 0;
        bool z = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                z = true;
                if (zero == 0) {
                    next_start = i + 1;
                    zero = 1;
                } else if (zero == 1) {
                    ans = max(ans, (i - 1 - curr_start));
                    curr_start = next_start;
                    next_start = i+1;
                    zero = 1;
                }
            }
            cout<<ans<<" ";
        }
        if (ans < nums.size() - curr_start - zero)
            ans = nums.size() - curr_start - zero;
            cout<<ans<<" ";
        if(!z)return ans-1;
        return ans;
    }
};