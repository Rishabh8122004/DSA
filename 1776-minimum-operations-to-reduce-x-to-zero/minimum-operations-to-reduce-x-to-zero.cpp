class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long>pref;
        pref.push_back(nums[0]);
        for(int i = 1;i<n;i++){
            pref.push_back(pref[i-1]+nums[i]);
        }
        int ans = 0;
        unordered_map<long long,int>mp;
        for(int i = 0;i<n;i++){
            if(mp.count(pref[i]) == 0) mp[pref[i]] = i;
        }
        for(int i = n-1;i>=0;i--){
            if(x == 0){
                ans = max(ans,i+1);
                break;
            }
            if(x < 0){break;}
            if(mp.count(x) && mp[x] <= i){
                ans = max(ans,i-mp[x]);
            }
            x-=nums[i];
        }
        if(x == 0 && ans == 0)return n;
        if(ans == 0)return -1;
        return n-ans;
    }
};