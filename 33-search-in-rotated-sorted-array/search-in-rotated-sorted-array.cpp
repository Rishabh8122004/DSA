class Solution {
public:
    int solve(int hi,int lo,vector<int>&nums,int &t){
        if(lo > hi)return -1;
        if(lo == hi){
            return (nums[lo] == t?lo:-1);
        }
        if(nums[lo]<nums[hi]){
            int mid = lo+(hi-lo)/2;
            if(nums[mid] == t)return mid;
            else if(nums[mid]>t)return solve(mid-1,lo,nums,t);
            else return solve(hi,mid+1,nums,t);
        }
        else if(nums[lo]>nums[hi]){
            int mid = lo+(hi-lo)/2;
            if(nums[mid] == t)return mid;
            return max(solve(mid-1,lo,nums,t),solve(hi,mid+1,nums,t));
        }
        return -1;
    }
    int search(vector<int>& nums, int t) {
        int lo = 0,hi = nums.size()-1;
        return solve(hi,lo,nums,t);
    }
};