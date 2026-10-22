class Solution {
public:
    int minOperations(vector<int>& nums) {
         int n = nums.size();
        int idx = -1;
        bool sorted = true;
        for(int i = 0;i<n;i++){
            if(nums[i] == n-1){idx = i;}
            if((i+1<n) && (nums[i]>nums[i+1]))sorted = false;
        }
        if(sorted)return 0;
        // checking if array is sortable
        int i = idx+1;
        bool inc = (nums[i%n] == 0);
        while(i-idx<n-1){
            if(inc){
                if(nums[i%n]+1 != nums[(i+1)%n])return -1;
            }else{
                if(nums[(i+1)%n]+1 != nums[i%n])return -1;
            }
            i++;
        }
        return min((1+(n-1-idx+1)),(idx+1));// either reverse then rotate , or first rotate till n-1 reach to 0 then reverse;
    }
};