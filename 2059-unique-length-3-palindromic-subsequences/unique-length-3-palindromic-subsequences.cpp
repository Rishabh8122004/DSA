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
                    v[s[i]-'a'] = true;
                    string b = s.substr(i+1,j-i-1);
                    sort(b.begin(),b.end());
                    int z = 1;
                    for(int k = 0;k<b.size()-1;k++){
                        if(b[k]!=b[k+1])z++;
                    }
                    c+=z;
                    break;
                }
            }
        }
        return c;
    }
};