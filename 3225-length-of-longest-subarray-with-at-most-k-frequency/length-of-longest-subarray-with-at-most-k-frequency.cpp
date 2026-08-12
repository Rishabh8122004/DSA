class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        bool f = false;
        int i = 0,j = 0,ans = 0;
        int n = nums.size();
        while(j<n){
            if(i>j)j = i;
            mp[nums[j]]++;
            if(mp[nums[j]]>k){
                f = true;
            }
            if(f){
                while(i<=j && mp[nums[j]]>k){
                    mp[nums[i]]--;
                    i++;
                }
                f = false;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};