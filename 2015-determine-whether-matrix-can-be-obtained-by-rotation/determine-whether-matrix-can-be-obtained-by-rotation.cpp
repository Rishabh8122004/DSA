class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        int n = mat.size();
        vector<vector<int>>t(n,vector<int>(n));
        int k = 0,l = 0;
        for(int j = 0;j<n;j++){
            l = 0;
            for(int i = n-1;i>=0;i--){
                t[k][l] = mat[i][j];
                l++;
            }
            k++;
        }
        mat = t;
        return;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& t) {
        int i = 3;
        if(mat == t)return true;
        while(i--){
            rotate(mat);
            if(mat == t)return true;
        }
        return false;
    }
};