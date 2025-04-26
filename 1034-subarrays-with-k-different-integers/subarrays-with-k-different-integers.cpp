class Solution {
public:
    int subarray(vector<int>&nums,int k)// finding subarray atmost k dstinct ele..
    {
        int n = nums.size();
        vector<int>v(20001);
        int ans = 0;
        int i = 0;
        for(int j = 0;j<n;j++){
            if(v[nums[j]] == 0)k--;
            v[nums[j]]++;
            // shrinking window if k<0 or distinct elements > k
            while(i<n && k<0){
                v[nums[i]]--;
                if(v[nums[i]] == 0)k++;
                i++;
            }
            ans+=(j-i+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarray(nums,k)-subarray(nums,k-1); // number of subarrays having exact distinct ele => k = at most(k)-at most(k-1);
    }
};