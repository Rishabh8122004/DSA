
class Solution {
public:  
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp; // nums[i] , index
        for(int i = 0;i<n;i++){
            mp[nums[i]] = i; 
        }
        for(int i = 0;i<nums.size();i++){
            if(mp.find(target-nums[i]) != mp.end()){
                if(mp[target-nums[i]] != i){
                    return{i,mp[target-nums[i]]};
                }
            }
        }
        return {};
    }
};