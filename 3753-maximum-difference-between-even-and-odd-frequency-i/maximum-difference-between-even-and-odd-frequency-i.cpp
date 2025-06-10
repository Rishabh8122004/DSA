class Solution {
public:
    int maxDifference(string s) {
        vector<int>v(26);
        int mine = s.size(),maxo = 0;
        for(int i = 0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        for(int i = 0;i<26;i++){
            if(v[i] == 0)continue;
            if(v[i]%2 == 0){
                mine = min(mine,v[i]);
            }
            else{
                maxo = max(maxo,v[i]);
            }
        }
        return maxo-mine;
    }
};