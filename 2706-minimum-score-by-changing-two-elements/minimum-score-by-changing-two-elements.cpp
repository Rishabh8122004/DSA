class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n == 3)return 0;
        return min( min(abs(nums[2]-nums[n-1]) , nums[n-3]-nums[0]) , nums[n-2]-nums[1]);
    }
};