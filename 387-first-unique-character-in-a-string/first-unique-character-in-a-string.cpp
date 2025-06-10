class Solution {
public:
    int firstUniqChar(string s) {
        queue<pair<char,int>>q;
        vector<bool>v(26);
        for(int i = 0;i<s.size();i++){
            if(v[s[i]-'a'] == true){
                int n = q.size();
                for(int j = 0;j<n;j++){
                   if(q.front().first!=s[i])q.push(q.front());
                   q.pop();
                }
                continue;
            }
            q.push({s[i],i});
            v[s[i]-'a'] = true;
        }
        if(q.empty())return -1;
        return q.front().second;
    }
};