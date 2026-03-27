class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(),m = mat[0].size();
        k%=m;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i%2 == 0){
                    int idx = j-k;
                    if(mat[i][(idx<0?(m+idx):idx)] != mat[i][j]) return false;
                }
                else{
                    int idx = j+k;
                    if(mat[i][(idx>=m?(idx%m):idx)] != mat[i][j])return false;
                }
            }
        }
        return true;
    }
};