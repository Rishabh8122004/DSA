class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        while(n>=1000){
            ans++;
            n--;
        }
        return ans;
    }
};