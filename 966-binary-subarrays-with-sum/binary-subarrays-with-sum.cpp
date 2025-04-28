class Solution {
public:
    int atmost(vector<int>&nums,int g){
        int i = 0,j = 0;
        int sum = nums[0];
        int ans = 0;
        while(i<nums.size() && j<nums.size()){
            if(j<i){j = i;sum = nums[j];}
            if(sum<=g){ans+=(j-i+1);j++;sum+=j<nums.size()?nums[j]:0;}
            else {sum-=nums[i];i++;}
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int g) {
        return atmost(nums,g)-atmost(nums,g-1);
    }
};