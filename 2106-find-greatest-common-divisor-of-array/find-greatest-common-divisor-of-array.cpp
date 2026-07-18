class Solution {
public:
    int gcd(int a,int b){
        if(b == 0)return a;
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int a = nums[0],b = nums[0];
        for(int i = 0;i<nums.size();i++){
            a = min(a,nums[i]);
            b = max(b,nums[i]);
        }
        return gcd(a,b);
    }
};