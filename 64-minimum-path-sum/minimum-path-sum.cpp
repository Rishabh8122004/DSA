class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int n = g.size(),m = g[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0 && j == 0)continue;
                if(i == 0) g[i][j]+=g[i][j-1];
                else if(j == 0)g[i][j]+=g[i-1][j];
                else g[i][j] += min(g[i][j-1],g[i-1][j]);
            }
        }
        return g[n-1][m-1];
    }
};