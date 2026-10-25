class Solution {
public:
    int n,m;
    int solve(int i,int j,vector<vector<int>>&g){
        if(i == n || i < 0 || j == m || j < 0)return false;
        if(g[i][j] == 1)return true;
        g[i][j] = 1;

        bool up_solve = solve(i-1,j,g);
        bool right_solve = solve(i,j+1,g);
        bool down_solve = solve(i+1,j,g);
        bool left_solve = solve(i,j-1,g);

        return (up_solve && right_solve && down_solve && left_solve);
    }
    int closedIsland(vector<vector<int>>& g) {
        n = g.size();m = g[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(g[i][j] == 0){
                    ans += (solve(i,j,g));
                }
            }
        }
        return ans;
    }
};