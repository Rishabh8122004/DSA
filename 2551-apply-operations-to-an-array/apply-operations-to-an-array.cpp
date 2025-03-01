class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i]*=2;
                nums[i+1] = 0;
                i++;
            }
        }
        int count = 0;
        for(int i = 0;i<nums.size()-count;i++){
            if(i == nums.size()-1) break;
            if(nums[i] == 0){
                count++;
                int j = i;
                while(j<nums.size()-1){swap(nums[j],nums[j+1]);j++;}
                i--;
            }
        }
        return nums;
    }
};