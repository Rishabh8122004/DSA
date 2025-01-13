class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int m = pref.size(),c=0;
        for(int i = 0 ;i<n;i++){
            if(m<=words[i].size() && pref == words[i].substr(0,m)){
                c++;
            }
        }
        return c;
    }
};