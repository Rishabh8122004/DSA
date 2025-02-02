class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];
        bool flag = false;
        for(int i = 0;i<n-1;i++){
            if(!flag && nums[i]<=nums[i+1]){a = min(nums[i+1],a);}
            if(!flag && nums[i]>nums[i+1]){
                flag = true;
                if(nums[i+1]>a)return false;
            }
            else if(flag && (nums[i]>nums[i+1] || nums[i+1]>a)){
                return false;
            }
        }
        return true;
    }
};