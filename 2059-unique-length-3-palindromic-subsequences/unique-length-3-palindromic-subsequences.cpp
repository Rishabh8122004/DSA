class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int c = 0;
        vector<bool> v(26,false);
        for(int i = 0;i+2<n;i++){
            if(v[s[i]-'a'] == true) continue;
            for(int j = n-1;j>=i+2;j--){
                if(s[i] == s[j]){
                    vector<bool>p(26,false);
                    v[s[i]-'a'] = true;
                    for(int k = i+1;k<j;k++){
                        c+=(!p[s[k]-'a']?1:0);
                        p[s[k]-'a'] = true;
                    }
                    break;
                }
            }
        }
        return c;
    }
};