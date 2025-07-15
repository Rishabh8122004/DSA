class Solution {
public:
    int climbStairs(int n) {
    if(n==1) return 1;
    if(n==2) return 2;
        int a = 1;
        int b = 2;
        int sum;
        for(int i = 2;i<n;i++)
        {
            sum = a+b;
            a=b;
            b = sum;
        }
        return sum;
    }
};