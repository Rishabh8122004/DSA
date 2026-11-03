class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = nums[0],n = nums.size();
        for(int i = 0;i<n;i++){
            m = max(nums[i],m);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans += (m-nums[i]);
        }
        return ans;
    }
};