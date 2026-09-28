class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int noo = 0;
        for(char & c: s){
            if(c == '(')noo++;
            if(c == ')')noo--;
            ans = max(noo,ans);
        }
        return ans;
    }
};