class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int> m(n);
        m[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            m[i] = max(m[i+1],nums[i]);
        }
        int max_val = nums[0];
        int max_diff = 0;
        for(int i = 1;i<n-1;i++){
            max_diff = max(max_diff,(max_val-nums[i]));
            long x = (long)(max_diff)*(long)(m[i+1]);
            if(x>ans)ans = x;
            max_val = max(max_val,nums[i]);
        }
        return ans;
    }
};