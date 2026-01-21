class Solution {
public:
    int get_value(int x){
       bitset<30>b(x);
       for(int i = 0;i<30;i++){
        if(b[i] == 0){
            i--;
            b[i] = 0;
            break;
        }
       }
       int ans = 0,a=1;
       for(int i = 0;i<30;i++){
        ans += (a*b[i]);
        a*=2;
       }
       return ans;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            if(nums[i]%2 == 0){nums[i] = -1;continue;}
            nums[i] = get_value(nums[i]);
        }
        return nums;
    }
};