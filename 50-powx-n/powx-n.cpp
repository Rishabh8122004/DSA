class Solution {
public:
    double ans = 1.0;
    double solve(double x,long long p){
        if(p == 0)return 1.0;
        if(p == 1)return x;
        double result = solve(x,p/2);
        result *= result;
        return (p%2 == 1?(x*result):result);
    }
    double myPow(double x, int n) {
        long long p = n;
        p = abs(p);
        double ans = solve(x,p);
       return (n<0?(1/ans):ans); 
    }
};