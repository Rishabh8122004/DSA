class Solution {
public:
    string clearDigits(string s) {
        stack<char> s1;
        for(int i = 0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9' && !s1.empty()) s1.pop();
            else s1.push(s[i]);
        }
        s = "";
        while(!s1.empty()){
            s = s1.top()+s;
            s1.pop();
        }
        return s;
    }
};