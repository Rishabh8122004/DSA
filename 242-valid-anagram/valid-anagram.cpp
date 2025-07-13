class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>sm;
        for(int i = 0;i<s.size();i++){
            sm[s[i]]++;
        }
        for(int i = 0;i<t.size();i++){
            if(!sm.count(t[i]))return false;
            sm[t[i]]--;
            if(sm[t[i]] == 0)sm.erase(t[i]);
        }
        if(!sm.empty())return false;
        return true;
    }
};