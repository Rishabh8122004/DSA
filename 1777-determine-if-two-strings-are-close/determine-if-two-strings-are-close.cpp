class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.size() != w2.size())return false;
        unordered_map<char,int>m1,m2;
        unordered_map<int,int>f1,f2;
        for(int i = 0;i<w1.size();i++){
            m1[w1[i]]++;
        }
        for(int i = 0;i<w2.size();i++){
            m2[w2[i]]++;
        }
        // a character schould be in both strings
        for(auto p:m1){
            if(m2.find(p.first) == m2.end())return false; // character not found in second string
            f1[p.second]++;
        }
        for(auto p:m2){
            if(m1.find(p.first) == m1.end())return false; // character not found in first string
            f2[p.second]++;
        }
        // checking if we can have character with equal frequency
        if(f1!=f2)return false;
        return true;
    }
};