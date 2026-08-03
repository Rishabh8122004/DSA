class Solution {
public:
int n;
    vector<int>dp;
    int solve(vector<int>&nums,int i){
        if(i >= n)return 0;
        if(dp[i]!= -1)return dp[i];
        int result = INT_MIN;
        result = max(result ,nums[i] - solve(nums,i+1));
        if(i+1<n){
            result = max(result,nums[i]+nums[i+1]-solve(nums,i+2));
            if(i+2<n) result= max(result,nums[i]+nums[i+1]+nums[i+2]-solve(nums,i+3));
        }
        return dp[i] =  result;
    }
    string stoneGameIII(vector<int>& nums) {
        n = nums.size();
        dp.resize(n+1,-1);
        int result = solve(nums,0);
        if(result == 0)return "Tie";
        if(result > 0)return "Alice";
        return "Bob";
    }
};