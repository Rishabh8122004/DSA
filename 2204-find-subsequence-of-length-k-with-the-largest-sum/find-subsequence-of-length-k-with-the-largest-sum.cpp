class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        if(k == nums.size())return nums;
        vector<pair<int,int>>v;
        for(int i = 0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int i = v.size()-1;bool f = false;
        vector<pair<int,int>>ans;
        while(k--){
            ans.push_back({v[i].second,v[i].first});
            i--;
        }
        sort(ans.begin(),ans.end());
        vector<int>p;
        for(int i = 0;i<ans.size();i++){
            p.push_back(ans[i].second);
        }
        return p;
    }
};