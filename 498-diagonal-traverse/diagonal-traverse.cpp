class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<int>ans;
        int i = 0,j = 0;
        bool f1 = true,f2 = true;
        while(true){
            while(i>=0 && j<m){
                ans.push_back(mat[i][j]);
                i--;
                j++;
            }
            if(i < 0 || j >= m){
                if(j>=m){i+=2;j--;}
                else if(j<m)i++;
            }
            if(i>=n || i < 0 || j < 0 || j>=m)break;
            while(i<n && j>=0){
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
            if(i>=n || j < 0){
                if(i>=n){i--;j+=2;}
                else if(i<n)j++;
            }
            if(i>=n || i < 0 || j < 0 || j>=m)break;
        }
        return ans;
    }
};