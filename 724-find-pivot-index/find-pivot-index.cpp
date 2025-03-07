class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>suffix(n);
        suffix[n-1] = nums[n-1];
        for(int i = nums.size()-2;i>=0;i--){
            suffix[i] = nums[i]+suffix[i+1];
        }
        if(nums[0] == suffix[0])return 0;
        for(int i = 1;i<n;i++){nums[i]+=nums[i-1]; if(nums[i] == suffix[i])return i;}
        return -1;
    }
};