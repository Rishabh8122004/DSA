class Solution {
public:
    int scoreOfParentheses(string s) {
        if(s == "()")return 1;
        int score = 0;
        int noo = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                noo++;
                int j = i;
                if(noo == 1){
                    while(j<s.size() && noo > 0){
                        j++;
                        noo += (s[j] == ')'?-1:1);
                    }
                    if(j-i+1 == 2)score += 1;
                    else if(j-i+1 > 2){
                        score += (2*(scoreOfParentheses(s.substr(i+1,(j-i-1)))));
                    }
                    i = j;
                }
            }
            else noo --;
        }
        return score;
    }
};