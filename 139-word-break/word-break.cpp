class Solution {
public:
int dp[305];
    bool isvalid(string s,set<string>&st){
        return st.find(s) != st.end();
    }
    bool solve(int i,string &s,set<string>&st){
        if(dp[i]!= -1)return dp[i];
         int n = s.size();
         int j = i;
            while(j<n){
                if(isvalid(s.substr(i,j-i+1),st)) {
                    if(j == n-1)return dp[i] = true;
                    if(solve(j+1,s,st))return dp[i] = true;
                }
                j++;
            }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& w) {
        memset(dp,-1,sizeof(dp));
        set<string>st;
        for(int i = 0;i<w.size();i++)st.insert(w[i]);
        return solve(0,s,st);
    }
};