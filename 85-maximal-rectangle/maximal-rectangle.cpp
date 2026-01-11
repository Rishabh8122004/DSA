class Solution {
public:
    int solve(vector<int>&v){
        int n = v.size();
        vector<int>leftest_short(n,-1),rightest_short(n,-1);
        stack<int>st;
        for(int i = 1;i<n;i++){
            st.push(i-1);
            while(!st.empty() && v[st.top()]>=v[i])st.pop();
            if(st.size())leftest_short[i] = st.top();
        }
        while(!st.empty())st.pop();
        for(int i = n-2;i>-1;i--){
            st.push(i+1);
            while(!st.empty() && v[st.top()]>=v[i])st.pop();
            if(st.size())rightest_short[i] = st.top();
        }
        int ans = 0;
        int x;
        for(int i = 0;i<n;i++){
            if(v[i] == 0)continue;
            x   = (leftest_short[i] == -1?v[i]*(i+1):v[i]*(i-leftest_short[i]));
            x  += (rightest_short[i] == -1?v[i]*(n-i):v[i]*(rightest_short[i]-i));
            x  -= v[i];
            ans = max(ans,x);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& g) {
        int n = g.size(),m = g[0].size();
        vector<vector<int>>len(n,vector<int>(m));
        for(int j = 0;j<m;j++){
            if(g[0][j] == '1')len[0][j]=1;
            for(int i = 1;i<n;i++){
                if(g[i][j] == '0')len[i][j] = 0;
                else len[i][j] = 1+len[i-1][j];
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans,solve(len[i]));
        }
        return ans;
    }
};