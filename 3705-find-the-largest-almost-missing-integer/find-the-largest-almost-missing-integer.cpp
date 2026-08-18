class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>v;
        for(int i = 0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        vector<bool>f(n,true);
        for(int i = 0;i<n-1;i++){
            if(v[i][0] == v[i+1][0]){
                f[v[i][1]] = false;
                f[v[i+1][1]] = false;
            }
        }
        int m = -1,m1 = -1;
        for(int i = 0;i<n;i++){
            if(f[i] && nums[i]>m)m = nums[i];
            if(nums[i] >m1)m1 = nums[i];
        }
        if(k == 1)return m;
        if(n == k)return m1;
        if(!f[0] && f[n-1]) return nums[n-1];
        if(f[0] && !f[n-1]) return nums[0];
        if(!f[0] && !f[n-1]) return -1;
        return max(nums[0],nums[n-1]);
    }
};