class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int>n(s.size()),l = n,r = n;
        int idx = -1;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '|'){n[i] = 1;idx = i;}
            if(i>0)n[i]+=n[i-1];
            l[i] = idx;
        }
        idx = s.size();
        for(int i = s.size()-1;i>=0;i--){
            if(s[i] == '|')idx = i;
            r[i] = idx;
        }
        vector<int>ans(queries.size());
        for(int i = 0;i<queries.size();i++){
            int a = queries[i][0],b = queries[i][1];
            if(l[b] != r[a]){ // Not only one '|'
                if(l[b] >= a && r[a] <= b){
                    ans[i] = (b-a+1) - (n[b]-(a == 0?0:n[a-1]));
                    ans[i] -= (r[a]-a);
                    ans[i] -= (b-l[b]);
                }
            }
        }
        return ans;
    }
};