class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int x = nums[0]+1;
        for(int i = 1;i<nums.size();i++){
            while(x<nums[i]){
                ans.push_back(x++);
            }
            x++;
        }
        return ans;
    }
};