class Solution {
public:
    int dp[501][501];
    int solve(vector<int>&nums,int i,int j){
        if(i>j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int take_i = nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
        int take_j = nums[j]+min(solve(nums,i+1,j-1),solve(nums,i,j-2));
        return dp[i][j] = max(take_i,take_j);
    }
    bool stoneGame(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int p1 = solve(nums,0,nums.size()-1),sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
        }
        return (sum-p1 > p1)?0:1;
    }
};