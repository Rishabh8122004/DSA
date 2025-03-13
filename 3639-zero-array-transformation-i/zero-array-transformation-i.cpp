class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1,0);
        for(int i = 0;i<queries.size();i++){
            diff[queries[i][0]]+=1;
            diff[queries[i][1]+1]-=1;
        }
        for(int i = 1;i<n;i++){
            diff[i]+=diff[i-1];
            if(nums[i]>diff[i])return false;
        }
        return nums[0]<=diff[0];
    }
};