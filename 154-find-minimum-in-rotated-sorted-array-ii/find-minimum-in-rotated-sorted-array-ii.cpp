class Solution {
public:
    int ans = 5000, mid;
    void solve(int lo, int hi, vector<int>& nums) {
        mid = lo + (hi - lo) / 2;
        if(hi<lo)return;
        if (lo == hi) {
            ans = min(ans, nums[mid]);
            return;
        }
        ans = min(ans, nums[mid]);
        if (nums[hi] < nums[lo]) {
            if (nums[mid] >= nums[lo]) { // to the right
                solve(mid+1,hi,nums);
            } else if (nums[mid] < nums[lo]) // to the left
                solve(lo,mid-1,nums);
        } else if (nums[hi] > nums[lo]) { // to the left 
           solve(lo,mid-1,nums);
        }
        else if(nums[hi] == nums[lo]){ // both ways
            solve(mid+1,hi,nums);
            solve(lo,mid-1,nums);
        }
        return;
    }
    int findMin(vector<int>& nums) {
        solve(0, nums.size() - 1, nums);
        return ans;
    }
};