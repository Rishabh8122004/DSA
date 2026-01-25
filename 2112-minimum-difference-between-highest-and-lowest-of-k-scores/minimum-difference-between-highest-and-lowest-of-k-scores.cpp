class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        for(int i = n-1;i-k+1>=0;i--){
            ans = min(ans,nums[i]-nums[i-k+1]);
        }
        return ans;
    }
};