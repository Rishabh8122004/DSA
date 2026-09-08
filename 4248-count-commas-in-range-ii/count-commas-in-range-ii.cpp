class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
            if(n==1e15){
                ans += (5);
                n--;
            }
            if(n>=1e12){
                ans += (4*(n-1e12+1));
                n = 1e12-1;
            }
            if(n >= 1e9){
                ans += (3*(n-1e9+1));
                n = 1e9-1;
            }
            if(n>= 1e6){
                ans += (2*(n-1e6+1));
                n = 1e6-1;
            }
            if(n>=1e3){
                ans += (n-1e3+1);
                n = 1e3-1;
            }
        return ans;
    }
};