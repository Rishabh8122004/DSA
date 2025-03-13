class Solution {
public:
    bool isvalid(vector<int>& nums, vector<vector<int>>& queries,int mid){
        int n = nums.size();
        vector<int>diff(n+1,0);
        for(int i = 0;i<=mid;i++){
            diff[queries[i][0]]+=queries[i][2];
            diff[queries[i][1]+1]-=queries[i][2];
        }
        for(int i = 0;i<n;i++){
            diff[i] += i==0?0:diff[i-1];
            if(nums[i]>diff[i])return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        bool f = true;
        for(int i = 0;i<n;i++){if(nums[i]!=0){f = false;break;}}
        if(f) return 0;
        int ans = -1;
        int lo = 0,hi = queries.size()-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(isvalid(nums,queries,mid)){ans = mid+1;hi=mid-1;}
            else lo = mid+1;
        }
        return ans;
    }
};