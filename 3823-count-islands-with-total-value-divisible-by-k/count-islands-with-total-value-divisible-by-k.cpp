class Solution {
public:
    int n,m;
    long long solve(int i,int j,vector<vector<int>>&g){
        if(i == n || i < 0 || j == m || j < 0)return 0;
        if(g[i][j] == 0)return 0;
        long long sum = g[i][j];
        g[i][j] = 0;

        sum += solve(i-1,j,g);
        sum += solve(i,j+1,g);
        sum += solve(i+1,j,g);
        sum += solve(i,j-1,g);

        return sum;
    }
    int countIslands(vector<vector<int>>& g, int k) {
        n = g.size();m = g[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(g[i][j] != 0){
                    ans += ((long long)solve(i,j,g)%(long long)k == 0);
                }
            }
        }
        return ans;
    }
};