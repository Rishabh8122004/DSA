class Solution {
public:
    int suffix[105],d = 1;
    void solve(set<vector<int>>&st,vector<int>&c,int &t,vector<int>&v,int i){
        if(t == 0){st.insert(v);}
        if(i == c.size() || suffix[i]<t ||(st.size()>=d && (c[0] == c.back() || c[0] == c[c.size()-2])))return;
        if(c[i]<=t){
        v.push_back(c[i]);
        t-=c[i];
        solve(st,c,t,v,i+1);
        v.pop_back();
        t+=c[i];
        }
        if(st.size()>=d && (c[0] == c.back() || c[0] == c[c.size()-2]))return;
        solve(st,c,t,v,i+1);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        suffix[c.size()] = 0;
        for(int i = c.size()-1;i>=0;i--){
            suffix[i] = c[i];
            suffix[i]+=suffix[i+1];
            if(i+1<c.size() && c[i] != c[i+1])d++; // number of distinct elements
        }
        set<vector<int>>st;
        vector<int>v;
        solve(st,c,t,v,0);
        vector<vector<int>>ans;
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};