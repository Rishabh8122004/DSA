class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        vector<int>ans(n);
        for(int i = 0;i<n;i++){
            if(i == 0 || i == n-1)ans[i] = nums[n-1]-(i == 0? nums[i]:nums[n-1]-nums[n-2]);
            else{
                ans[i] = abs(nums[i-1]-(nums[n-1]-nums[i]));
            }
        }
        return ans;
    }
};