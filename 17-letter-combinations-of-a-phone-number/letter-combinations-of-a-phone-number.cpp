class Solution {
public:
    void solve(string d,vector<string>&ans,vector<vector<char>>&v,string s,int idx){
        //if(idx>=d.size())return;
        if(s.size() == d.size()){ans.push_back(s);return;}
        for(int i = 0;i<v[d[idx]-'0'].size();i++){
            solve(d,ans,v,s+v[d[idx]-'0'][i],idx+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "")return {};
        vector<vector<char>>v(10); // mapping the respected characters..
        char x = 'a';
        for(int i = 2;i<=6;i++){
            for(int j = 0;j<3;j++)v[i].push_back(x++);
        }
        for(int i = 0;i<4;i++)v[7].push_back(x++);
        for(int i = 0;i<3;i++)v[8].push_back(x++);
        for(int i = 0;i<4;i++)v[9].push_back(x++);
        // for(int i = 0;i<v.size();i++){
        //     for(int j = 0;j<v[i].size();j++){cout<<v[i][j]<<"  ";}cout<<endl;
        // }
        vector<string>ans;
        solve(digits,ans,v,"",0);
        return ans;
    }
};