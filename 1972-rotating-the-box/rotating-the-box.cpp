class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& g) {
        int n = g.size(),m = g[0].size();
        vector<vector<char>>ans(m,vector<char>(n,'.'));
        // filling the rotated matrix while keeping the positions of stones just above the obstacle/next stone/floor
        for(int i = 0;i<n;i++){
            int k = m-1;
            for(int j = m-1;j>=0;j--){
                if(g[i][j] == '*'){
                   ans[j][n-i-1] = g[i][j]; // an obstacle position won't change
                   k = j-1; // obstacle is something which can hold stones above it.. k = j-1.
                }
                else if(g[i][j] == '#'){
                    ans[k][n-i-1] = g[i][j]; // only move k to the left when being placed a stone.
                    k--;
                }
            }
        }
        return ans;
    }
};