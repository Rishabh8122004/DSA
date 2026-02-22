class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int a = 0;
        bool f = false;
        while(n){
            a++;
            if(n%2 == 1){
                if(f)ans = max(ans,a);
                a = 0;
                f = true;
            }
            n/=2;
        }
        return ans;
    }
};