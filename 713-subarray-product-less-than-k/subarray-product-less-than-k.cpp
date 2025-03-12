class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        if(k<=1)return 0;
        int n = nums.size();
        int i = 0, j = 0;
        int prod = 1;
        while(j<n){
            prod*=nums[j];
            while(prod>=k && i<n){prod/=nums[i++];}
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
};