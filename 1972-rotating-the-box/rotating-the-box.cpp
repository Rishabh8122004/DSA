class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& g) {
        int n = g.size(),m = g[0].size();
        // moving stones to the right
        for(int i = 0;i<n;i++){
            for(int j = m-1;j>=0;j--){
                if(g[i][j] == '#'){
                    int k = j;
                    while(k+1<m && g[i][k+1] == '.'){
                        swap(g[i][k],g[i][k+1]);
                        k++;
                    }
                }
            }
        }
        vector<vector<char>>ans(m,vector<char>(n,'.'));
        for(int j = 0;j<m;j++){
            vector<char>v(n);
            for(int i = n-1;i>=0;i--){
                v[n-1-i] = g[i][j];
            }
            ans[j] = v;
        }
        return ans;
    }
};