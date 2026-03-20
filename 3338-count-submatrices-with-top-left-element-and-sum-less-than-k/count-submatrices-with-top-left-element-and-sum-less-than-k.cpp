class Solution {
public:
    int countSubmatrices(vector<vector<int>>& g, int k) {
        int n = g.size(),m = g[0].size();
        for(int j = 0;j<m;j++){ // column wise prefix calculation
            for(int i = 1;i<n;i++){
                g[i][j]+=g[i-1][j];
            }
        }
        // row wise iteration
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(j != 0){
                    g[i][j] += g[i][j-1];
                }
                if(g[i][j] <= k)ans++;
                else break;
            }
        }
        return ans;
    }
};