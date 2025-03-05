class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long p = (n%2 == 0?((long long )(n/2)*(n - 1)):((long long )n*((n-1)/2)));
        for (int i = 0; i < nums.size(); i++) {
            nums[i] -= i;
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>>v;
        v.push_back({nums[0]});
        for (int i = 1; i < nums.size(); i++) {
            if(v[v.size()-1][0] == nums[i])v[v.size()-1].push_back(nums[i]);
            else v.push_back({nums[i]});
        }
        for(int i = 0;i<v.size();i++){
            if(v[i].size()>1){
                long long c = v[i].size();
                p-=(c*(c-1)/2);
            }
        }
        return p;
    }
};