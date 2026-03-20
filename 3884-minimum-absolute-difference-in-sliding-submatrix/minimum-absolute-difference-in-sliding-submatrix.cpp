class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& g, int k) {
        int n = g.size(),m = g[0].size();
        if(k == 1){
            vector<vector<int>>v(n-k+1,vector<int>(m-k+1,0));
            return v;
        }
        vector<int>v;
        vector<vector<int>>ans;
        for(int i = 0;i<=n-k;i++){
            ans.push_back({});
            for(int j = 0;j<=m-k;j++){
                v = {};
                for(int x = i;x<i+k;x++){
                    for(int y = j;y<j+k;y++){
                        v.push_back(g[x][y]);
                    }
                }
                sort(v.begin(),v.end());
                int min_diff = INT_MAX;
                for(int x = 0;x<v.size()-1;x++){
                    if(v[x] != v[x+1]){
                        min_diff = min(min_diff,abs(v[x]-v[x+1]));
                    }
                }
                if(min_diff == INT_MAX)min_diff = 0;
                ans[i].push_back(min_diff);
            }
        }
        return ans;
    }
};