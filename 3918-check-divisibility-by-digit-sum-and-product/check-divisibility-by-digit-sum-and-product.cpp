class Solution {
public:
    bool checkDivisibility(int n) {
        int s= 0,p = 1;
        int x = n;
        while(x){
            s+=(x%10);
            p*=(x%10);
            x/=10;
        }
        return (n%(s+p) == 0);
    }
};