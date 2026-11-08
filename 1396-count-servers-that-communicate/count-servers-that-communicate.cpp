class Solution {
public:
    int countServers(vector<vector<int>>& g) {
        int n = g.size(),m = g[0].size();
        vector<int>r(n),c(m);
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(g[i][j] == 1){
                    r[i]++;
                    c[j]++;
                    ans++;
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(g[i][j] == 1){
                    if(r[i] <= 1 && c[j] <= 1)ans--;
                }
            }
        }
        return ans;
    }
};