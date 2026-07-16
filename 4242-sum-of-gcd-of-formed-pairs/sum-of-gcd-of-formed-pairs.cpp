class Solution {
public:
    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int m = nums[0];
        for(int i = 0;i<n;i++){
            m = max(m,nums[i]);
            nums[i] = gcd(nums[i],m);
        }
        sort(nums.begin(),nums.end());
        long long sum = 0;
        int i = 0,j = n-1;
        while(i<j){
            sum+=gcd(nums[i],nums[j]);
            i++;
            j--;
        }
        return sum;
    }
};