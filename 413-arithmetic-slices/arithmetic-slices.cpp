class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)return 0;
        int len = 2;
        int ans = 0;
        int d = nums[n-1]-nums[n-2];
        for(int i = n-2;i>0;i--){
            if(nums[i]-nums[i-1] != d){
                ans += ((len-2)*(len-1))/2;
                len = 2;
                d = nums[i]-nums[i-1]; 
            }
            else len++;
        }
        ans += ((len-2)*(len-1))/2;
        return ans;
    }
};