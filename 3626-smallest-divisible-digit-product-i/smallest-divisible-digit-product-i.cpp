class Solution {
public:
    int smallestNumber(int n, int t) {
        int a = n;
        while(true){
            int prod = 1;
            int ans = a;
            while(a>0){
                prod*=(a%10);
                a/=10;
            }
            if(prod%t == 0) return ans;
            else {ans++;a = ans;}
        }
        return 0;
    }
};