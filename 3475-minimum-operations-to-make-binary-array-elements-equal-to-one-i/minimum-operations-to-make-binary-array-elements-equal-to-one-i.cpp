class Solution {
public:
    void flip(vector<int>& nums,int i,int j){
        while(i<=j){
            nums[i] = (nums[i] == 0?1:0);
            i++;
        }
        return;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool f = true;
        int i = 0,j = 2;
        while(j<nums.size()){
            f = true;
            if(nums[i] == 0){
                f = false;
            }
            if(!f){flip(nums,i,j);ans++;}
            i++;j++;
        }
        if(nums[n-1] != nums[n-2] || nums[n-1] != nums[n-3]){return -1;}
        if(nums[n-1] == nums[n-2] && nums[n-1] == nums[n-3] && nums[n-1] == 0){ans++;}
        return ans;
    }
};