class Solution {
public:
    int n;
    bool solve(vector<int>& nums, int& t, int lo, int hi) {
        if (lo > hi)
            return false;
        if (hi < 0 || lo > n - 1)
            return false;
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == t || nums[lo] == t || nums[hi] == t)
            return true;
        if (hi == lo)
            return false;
        if ((nums[lo] == nums[hi]) && (nums[lo] <= nums[hi])) {
            return solve(nums, t, lo + 1, hi - 1);
        }
        if(nums[lo]<=nums[mid]){
            if(t>=nums[lo] && t<nums[mid])return solve(nums,t,lo,mid-1);
            else return solve(nums,t,mid+1,hi);
        }
        else if(nums[mid]<=nums[hi]){
            if(t <= nums[hi] && t > nums[mid])return solve(nums,t,mid+1,hi);
            else return solve(nums,t,lo,mid-1);
        }
        return false;
    }
    bool search(vector<int>& nums, int t) {
        n = nums.size();
        return solve(nums, t, 0, n - 1);
    }
};