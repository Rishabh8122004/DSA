class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        vector<long long>ans(nums.size());
        for(auto &p : mp){
            auto v = p.second;
            long long sum = 0;
            for(auto j : v){
                sum += j;
            }
            long long left_sum = 0;
            int m = v.size();
            for(int i = 0;i<m;i++){
                long long right_sum = sum-left_sum-v[i];

                long long left = 1LL * v[i] * i - left_sum;
                long long right = right_sum - 1LL * v[i] * (m-i-1); 

                ans[v[i]] = left+right;

                left_sum += v[i];
            }
        }
        return ans;
    }
};