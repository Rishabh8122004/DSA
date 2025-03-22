class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool>v(m,true);
        vector<bool>v1(n,true);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 0){v[i] = false;v1[j] = false;}
            }
        }
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!v[i] || !v1[j]) matrix[i][j] = 0;
            }
        }
        return ;
    }
};