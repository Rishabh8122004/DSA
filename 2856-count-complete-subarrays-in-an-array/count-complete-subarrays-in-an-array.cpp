class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int td = 0,nod = 0;//total distinct , number of distinct
        vector<int>v(2001,0),f(2001,0);
        for(int i = 0;i<nums.size();i++){v[nums[i]]++;if(v[nums[i]] == 1)td++;}
        for(int i = 0;i<nums.size();i++){v[nums[i]] = 0;}
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            v = f;
            nod = 0;
            for(int j = i;j<nums.size();j++){
                v[nums[j]]++;
                if(v[nums[j]] == 1)nod++;
                if(nod == td)ans++;
            }
        }
        return ans;
    }
};