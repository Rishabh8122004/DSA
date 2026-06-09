class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ma = nums[0],mi = ma;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>ma)ma = nums[i];
            if(nums[i]<mi)mi = nums[i];
        }
        return k*(ma-mi);
    }
};