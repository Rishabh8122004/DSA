class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int msum = 0;
        int sum = 0;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){sum+=nums[i];}
            if(i+1 == nums.size()-1 && nums[i]<nums[i+1]){sum+=nums[i+1];msum = max(msum,sum);}
            if(nums[i]>=nums[i+1]){
                sum+=nums[i];
                msum = max(msum,sum);
                sum = 0;
            }
        }
       msum = max(msum,nums[nums.size()-1]);
        return msum;
    }
};