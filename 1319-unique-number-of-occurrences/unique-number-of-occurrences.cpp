class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_set<int>s;
        for(int i = 0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto p:mp){
            if(s.find(p.second) != s.end())return false;
            s.insert(p.second);
        }
        return true;
    }
};