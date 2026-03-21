class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int a = x,b =x+k-1;
        int j = y;
        while(a<b){
            j = y;
            while(j<y+k){
                swap(grid[a][j],grid[b][j]);
                j++;
            }
            a++;
            b--;
        }
        return grid;
    }
};