class Solution {
public:
    long long calculateScore(string s) {
        int n = s.size();
        long long int ans = 0;
        vector<vector<int>>v;
        for(int i = 0;i<26;i++)v.push_back({-1});
        bool flag = true;
        for(int i = 1;i<n;i++){
            if(flag) v[s[i-1]-'a'].push_back(i-1);
            flag = true;
            if(v['z'-s[i]].size()>1){
                ans+=(i-v['z'-s[i]][v['z'-s[i]].size()-1]);
                v['z'-s[i]].pop_back();
                flag = false;
            }
        }
        return ans;
    }
};