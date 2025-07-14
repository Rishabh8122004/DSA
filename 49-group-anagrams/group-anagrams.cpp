class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int level = 0;
        unordered_map<string,vector<string>>mp; // sorted string adn it's correspoinding index to be stored in a 2d answer vector
        for(int i = 0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            vector<string>v = mp[s];
            v.push_back(strs[i]);
            mp[s] = v;
        }
        vector<vector<string>>ans; // no of string vectors
        for(auto p: mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};