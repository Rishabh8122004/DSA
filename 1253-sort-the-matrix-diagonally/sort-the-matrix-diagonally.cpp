class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        for(int k = m-2;k>=0;k--){
            vector<int>v;
            int j = k,i = 0;
            while(i<n && j<m){
                v.push_back(mat[i][j]);
                i++;j++;
            }
            sort(v.begin(),v.end());
            j = k,i = 0;
            while(i<n && j<m){
                mat[i][j] = v[i];
                i++;j++;
            }
        }
        for(int k = 1;k<n-1;k++){
            vector<int>v;
            int i = k,j = 0;
            while(i<n && j<m){
                v.push_back(mat[i][j]);
                i++;j++;
            }
            sort(v.begin(),v.end());
            i = k,j = 0;
            while(i<n && j<m){
                mat[i][j] = v[j];
                i++;j++;
            }
        }
        return mat;
    }
};