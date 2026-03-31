class Solution {
public:
    int maxSum(vector<vector<int>>& g) {
        int n = g.size(),m = g[0].size();
        int ans = 0,sum = 0;
        for(int i = 0;i<n-2;i++){
            for(int j = 0;j<m-2;j++){
                sum = 0;
                sum = (g[i][j]+g[i][j+1]+g[i][j+2]);
                sum += (g[i+2][j]+g[i+2][j+1]+g[i+2][j+2]);
                sum += (g[i+1][j+1]);
                ans = max(sum,ans);
            }
        }
        return ans;
    }
};