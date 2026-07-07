class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = "";
        long long x = 0;
        while(n){
            char ch = char('0'+(n%10));
            if(ch != '0')s = (ch)+s;
            n/=10;
        }
        long long sum = 0;
        for(char ch:s){
            x*=10;
            x += (ch-'0');
            sum+=(ch-'0');
        }
        return x*sum;
    }
};