class Solution {
public:
    int siz(int n){
        int c = 0;
        while(n>0){
            n/=10;c++;
        }
        return c;
    }
    int alternateDigitSum(int n) {
        bool flag = (siz(n)%2 == 0?false:true);
        int ans = 0;
        while(n>0){
            ans+=(flag?(n%10):(-(n%10)));
            n/=10;
            flag = !flag;
        }
        return ans;
    }
};