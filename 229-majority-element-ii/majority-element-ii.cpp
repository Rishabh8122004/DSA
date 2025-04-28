class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 2 && nums[0]!=nums[1])return nums;
        if(n == 1)return nums;
        sort(nums.begin(),nums.end());
        int x = nums.size()/3;
        int c = 1;
        vector<int>ans;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1])c++;
            else c = 1;
            if(c >= x+1){ans.push_back(nums[i]); while(i<n-1 && nums[i] == nums[i+1])i++; c = 1;}
        }
        return ans;
    }
};