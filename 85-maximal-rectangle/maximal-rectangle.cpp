class Solution {
public:
    int solve(vector<int>&v){
        int n = v.size();
        vector<int>leftest_short(n,-1),rightest_short(n,-1);
        stack<int>st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && v[st.top()]>=v[i])st.pop();
            if(st.size())leftest_short[i] = i-st.top();
            else leftest_short[i] = i+1;
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i = n-1;i>-1;i--){
            while(!st.empty() && v[st.top()]>=v[i])st.pop();
            if(st.size())rightest_short[i] = st.top()-i;
            else rightest_short[i] = n-i;
            st.push(i);
        }
        int ans = 0;
        int x;
        for(int i = 0;i<n;i++){
            if(v[i] == 0)continue;
            x   = v[i]*(leftest_short[i]);
            x  += v[i]*(rightest_short[i]);
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