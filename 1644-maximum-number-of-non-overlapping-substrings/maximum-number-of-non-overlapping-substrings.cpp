class Solution {
public:
    vector<string> maxNumOfSubstrings(string x) {
        int n = x.size();
        vector<int> s(26,n),e(26,-1),is_valid(n+1,1);
        for(int i = 0;i<n;i++){
            s[x[i]-'a'] = min(s[x[i]-'a'],i);
            e[x[i]-'a'] = max(e[x[i]-'a'],i);
        }
        for(int c = 0;c<26;c++){

            for(int j = s[c];j<=e[c];j++){
                if(s[x[j]-'a'] < s[c])is_valid[s[c]] = 0; // can not start substring from the character because the characters in between are appearing before the substring started
                e[c] = max(e[c],e[x[j]-'a']); // increasing the substring size because other character has appearence afterwards
            }

        }
        vector<string>ans;
        int last_taken = n;// lets assume the last substring we picked was at idx 'n'
        for(int i = n-1;i>=0;i--){
            if(is_valid[i] == 0)continue;

            int c = x[i]-'a';
            if(i == s[c] && last_taken > e[c]){
                last_taken = i;
                ans.push_back(x.substr(i,e[c]-s[c]+1));
            }
        }
        return ans;
    }
};