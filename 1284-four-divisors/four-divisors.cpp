class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = 0,c = 0;
        int hi, lo;
        for(int i = 0;i<n;i++){
            c = 0;
            hi = sqrt(nums[i]);
            lo = 2;
            while(hi>=lo){
                if(nums[i]%hi == 0){
                    if(hi == (nums[i]/hi)){
                        c = 3;
                    }
                    c++;
                    sum = (hi+(nums[i]/hi));
                }
                hi--;
                if(c>1){break;} 
            }
            if(c == 1){
                ans+=(sum+nums[i]+1);
            }
            sum = 0;
        }
        return ans;
    }
};