class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        int i = 0,j = 0;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum<0){i = j;sum = 0;}
            ans = max(sum,ans);
            j++;
        }
        i = 0;j = 0;
        sum = 0;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum>0){i = j;sum = 0;}
            ans = max(abs(sum),ans);
            j++;
        }
        return ans;
    }
};