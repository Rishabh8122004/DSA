class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& g) {
        int n = g.size(),m = g[0].size();
        vector<vector<char>>ans(m,vector<char>(n,'.'));
        // moving stones to the right
        for(int i = 0;i<n;i++){
            int k = m-1;
            for(int j = m-1;j>=0;j--){
                if(g[i][j] == '*'){
                   ans[j][n-i-1] = g[i][j];
                   k = j-1;
                }
                else if(g[i][j] == '#'){
                    ans[k][n-i-1] = g[i][j];
                    k--;
                }
            }
        }
        return ans;
    }
};