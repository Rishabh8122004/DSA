class Solution {
public:
    bool isvowel(char ch){
        return ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'));
    }
    int beautifulSubstrings(string s, int k) {
        int ans = 0,v = 0,c = 0;
        for(int i = 0;i<s.size()-1;i++){
            if(isvowel(s[i]))v++;
            else c++;
            for(int j = i+1;j<s.size();j++){
                if(isvowel(s[j]))v++;
                else c++;
                if((c == v) &&((c*v)%k == 0)) ans++;
            }
            v = 0,c = 0;
        }
        return ans;
    }
};