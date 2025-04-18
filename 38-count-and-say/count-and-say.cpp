class Solution {
public:
    string countAndSay(int n) {
        if(n==1){return "1";}
        string s = countAndSay(n-1);
        string s2 = "";
        for(int i = 0;i<s.size();i++)
        {
            int count = 1;
            while(s[i] == s[i+1] && i+1<s.size()){count++;i++;}
            char dh = s[i];
            s2  += (to_string(count)+dh);
        }
        return s2;
    }
};