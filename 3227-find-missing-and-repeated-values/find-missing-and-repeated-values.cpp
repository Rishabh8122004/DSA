class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>v(n*n);
        vector<int> ans;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(v[grid[i][j]-1] == 0){v[grid[i][j]-1] = 1;}
                else{ans.push_back(grid[i][j]);}
            }
        }
        for(int i = 0;i<v.size();i++){
            if(v[i] == 0)ans.push_back(i+1);
        }
        return ans;
    }
};