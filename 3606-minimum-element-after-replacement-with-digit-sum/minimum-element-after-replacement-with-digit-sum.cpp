class Solution {
public:
    int get_sum(int x){
        int ans  = 0;
        while(x){
            ans += (x%10);
            x/=10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int ans = 1e9;
        for(int i =0 ;i<nums.size();i++){
            ans = min(ans,get_sum(nums[i]));
        }
        return ans;
    }
};