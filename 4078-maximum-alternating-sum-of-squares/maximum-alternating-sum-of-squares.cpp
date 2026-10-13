class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++)nums[i] = abs(nums[i]);
        sort(nums.begin(),nums.end());
        long long ans = 0;
        int i = 0,j = nums.size()-1;
        while(i<=j){
            ans += (nums[j]*nums[j]);
            if(i < j) ans -= (nums[i]*nums[i]);
            j--;i++;
        }
        return ans;
    }
};