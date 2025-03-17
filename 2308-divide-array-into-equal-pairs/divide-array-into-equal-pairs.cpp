class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int>v(501);
        for(int i = 0;i<nums.size();i++){
            v[nums[i]] += (v[nums[i]]>0?-1:1);
        }
        for(int i = 0;i<v.size();i++){
            if(v[i]>0)return false;
        }
        return true;
    }
};