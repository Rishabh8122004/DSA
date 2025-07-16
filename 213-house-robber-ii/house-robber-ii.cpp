class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 3) return max(nums[0],max(nums[1],nums[2]));
        vector<int>dp = nums;
        for(int i = 3;i<n;i++){
            if(i-3 >= 1)nums[i]+=max(nums[i-3],nums[i-2]);
            else if(i-2 >= 1)nums[i]+=nums[i-2];
        }
        for(int i = n-4;i>=0;i--){
            if(i+3 <= n-2)dp[i]+=max(dp[i+3],dp[i+2]);
            else if(i+2 <= n-2)dp[i]+=dp[i+2];
        }
        return max(max(dp[0],dp[1]),max(nums[n-2],nums[n-1]));
    }
};