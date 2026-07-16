class Solution {
public:
    int gcd(int a,int b){
        if(b == 0)return a;
        return gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        return n;
        int e = 0,o = 0;
        int x = 1;
        for(int i = 1;i<=n;i++){
            e+=x+1;
            o+=x;
            x+=2;
        }
        return gcd(o,e);
    }
};