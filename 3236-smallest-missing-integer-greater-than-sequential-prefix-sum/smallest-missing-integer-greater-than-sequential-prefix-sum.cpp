class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int sum = nums[0];
        int i = 1;
        while((i<n) && (nums[i] == nums[i-1]+1)){
            sum += nums[i];
            i++;
        }
        for(auto p: nums)mp[p]++;
        while(1){
            if(mp.count(sum) == 0)return sum;
            sum++;
        }
        return -1;
    }
};