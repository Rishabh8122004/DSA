class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxlen = 1,increase = 1,decrease = 1;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){increase++;decrease = 1;}
            else if(nums[i]>nums[i+1]){decrease++;increase = 1;}
            else{increase = 1;decrease = 1;}
            maxlen = max(increase,maxlen);
            maxlen = max(maxlen,decrease);
        }
        return maxlen;
    }
};