class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        bool flag = true;
        for(int i = 0;i<s.size();i++){
            if(s[i] >= '0' && s[i]<='9'){
                flag = false;
                ans+=i>0?s.substr(0,i-1):"";
                ans+=i<s.size()-1?s.substr(i+1,s.size()-1-i):"";
                break;
            }
        }
        if(flag) return s;
        return clearDigits(ans);
    }
};