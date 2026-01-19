class Solution {
public:
    int isvalid_divisor(int &mid,vector<int>&nums){
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]%mid == 0)sum+=(nums[i]/mid);
            else sum+=(nums[i]/mid)+1;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int lo = 1,hi = 0;
        for(int i = 0;i<n;i++)hi = max(hi,nums[i]);
        int ans = INT_MAX;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isvalid_divisor(mid,nums)<=threshold){ans = min(ans,mid);hi = mid-1;}
            else lo = mid+1;
        }
        return ans;
    }
};