class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 1;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]%2 == nums[i+1]%2)return false;
        }
        return true;
    }
};