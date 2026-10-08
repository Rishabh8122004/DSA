class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int noo = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                if(noo == 0){
                    int j = i+1;
                    while((s[j]!=')') || (noo != 0)){
                        noo += ((s[j] == '(')?1:-1);
                        j++;
                    }
                    ans += s.substr(i+1,j-i-1);
                    i = j;
                }else noo ++;
            }else noo --;
        }
        return ans;
    }
};