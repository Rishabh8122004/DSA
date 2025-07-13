class Solution {
public:
    int reverse(int x){
        int ans = 0;
        while(x){
            ans = (ans*10)+(x%10);
            x/=10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>s;
        for(int i = 0;i<nums.size();i++){
            s.insert(nums[i]);
            s.insert(reverse(nums[i]));
        }
        return s.size();
    }
};