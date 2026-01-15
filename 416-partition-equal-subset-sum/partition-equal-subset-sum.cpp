class Solution {
public:
    int dp[201][20005];
    bool solve(int i,vector<int>&nums,int sum){
        if(sum == 0)return true;
        if(i==nums.size())return false;
        if(dp[i][sum]!= -1)return dp[i][sum];
        bool take = (nums[i]<=sum?solve(i+1,nums,sum-nums[i]):false);
        bool not_take = solve(i+1,nums,sum);
        return dp[i][sum] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++)sum+=nums[i];
        if(sum%2 != 0)return false;
        sum/=2;
        return solve(0,nums,sum);
    }
};