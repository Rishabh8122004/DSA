class Solution {
public:
    string convertToTitle(int cn) {
        string ans = "";
        while(cn>0){
            ans = (char)(((cn-1)%26)+'A') + ans;
            cn--;
            cn/=26;
        }
        return ans;
    }
};