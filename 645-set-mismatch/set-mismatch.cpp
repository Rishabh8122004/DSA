class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool> v(n+1,false);
        vector<int>ans(2);
        for(int i = 0;i<n;i++){
            if(v[nums[i]] == true)ans[0] = nums[i];
            v[nums[i]] = true;
        }
        for(int i = 0;i<=n;i++){
            if(v[i] == false)ans[1] = i;
        }
        return ans;
    }
};