class Solution {
public:
    bool can_be_robbed(int x,int k,vector<int>& nums){
        int c = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<=x)
            {c++;
            i++;}
        }
        return c>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int max = 0;
        for(int i = 0;i<nums.size();i++){if(max<nums[i])max = nums[i];}
        int lo = 1,hi = max;
        int ans = INT_MAX;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(can_be_robbed(mid,k,nums)){ans = mid;hi = mid-1;}
            else lo = mid+1;
        }
        return ans;
    }
};