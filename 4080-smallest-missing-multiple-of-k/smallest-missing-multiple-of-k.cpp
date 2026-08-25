class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int x = k;
        while(1){
            if(mp[k] == 0)return k;
            k+=x;
        }
        return -1;
    }
};