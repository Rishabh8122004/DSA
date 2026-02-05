class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0) result.push_back(nums[i]);
            else if(nums[i]>0){
                result.push_back(nums[(i+nums[i])%n]);
            }
            else{
                int j  = i+nums[i];
                while(j<0) j+=n;
                result.push_back(nums[(j)]);
            }
        }
        return result;
    }
};