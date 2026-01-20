class Solution {
public:
    int get_value(int x){
        for(int i = 0;i<x;i++){
            if((i | i+1) == x)return i;
        }
        return -1;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            nums[i] = get_value(nums[i]);
        }
        return nums;
    }
};