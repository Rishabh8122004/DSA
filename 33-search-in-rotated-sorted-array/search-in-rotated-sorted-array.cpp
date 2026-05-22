class Solution {
public:
    int solve(int hi,int lo,vector<int>&nums,int &t){
        if(lo > hi)return -1;
        if(lo == hi){
            return (nums[lo] == t?lo:-1);
        }
        int mid = lo+(hi-lo)/2;
        if(nums[mid] == t)return mid;
        else if(nums[mid]>t)return solve(mid-1,lo,nums,t);
        else return solve(hi,mid+1,nums,t);
        return -1;
    }
    int search(vector<int>& nums, int t) {
        int lo = 0,hi = nums.size()-1;
        int pi = -1;//pivot index
        int ele = -10005;// possible minimum element in the array 
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(ele<nums[mid]){
                pi = mid;
                ele = nums[mid];
            }
            if(lo == hi)break;
            if(nums[lo]>nums[hi]){
                if(nums[mid]<nums[lo])hi = mid-1;
                else lo = mid+1;
            }
            else if(nums[lo]<nums[hi])lo = mid+1;
        }
        if(nums[0]<=t && nums[pi]>=t)return solve(pi,0,nums,t);
        else if(pi+1<nums.size() && nums[nums.size()-1]>=t && nums[pi+1]<=t)return solve(nums.size()-1,pi+1,nums,t);
        return -1;
    }
};