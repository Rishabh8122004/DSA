class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i = 0;i<n;i++)s+=nums[i];
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans += (i*nums[i]);
        }
        int res = ans;
        for(int i = 1;i<n;i++){
            res -= (s-nums[i-1]);
            res += ((n-1)*nums[i-1]);
            ans = max(ans,res);
        }
        return ans;
    }
};