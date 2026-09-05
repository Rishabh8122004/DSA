class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>min_n;
        int n = nums.size();
        min_n = nums;
        int m = nums[n-1];
        for(int i = n-1;i>=0;i--){
            m = min(m,nums[i]);
            min_n[i] = m;
        }
        m = nums[0];
        for(int i = 0;i<n;i++){
            m = max(m,nums[i]);
            if(m-min_n[i] <= k)return i;
        }
        return -1;
    }
};