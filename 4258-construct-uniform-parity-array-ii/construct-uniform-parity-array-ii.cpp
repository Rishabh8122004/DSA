class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        for(int i = 1;i<n;i++){
            x = min(x,nums[i]);
        }
        if(x%2 == 0){ // smallest is even i.e. we can just iterate the array to check if there is no odd
            bool f = true;
            for(int i = 0;i<n;i++){
                if(nums[i]%2 == 1){
                    f = false;
                    break;
                }
            } 
            if(f)return true;
        }
        else{ // smallest is odd i.e. if there exist any even , we can make that odd so just return true;
        return true;
        }
        return false;
    }
};