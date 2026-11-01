class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = nums[0];
        for(auto &a:nums){
            m = min(m,a);
        }
        int ans = 0;
        for(auto &a : nums){
            ans += (a-m);
        }
        return ans;
    }
};