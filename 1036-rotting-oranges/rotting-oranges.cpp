class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        while(true){
            bool flag = true;
            vector<vector<int>>v;
            for(int i = 0;i<grid.size();i++){
                for(int j = 0;j<grid[i].size();j++){
                    if(grid[i][j] == 1){
                        if(i>0 && grid[i-1][j] == 2){flag = false;v.push_back({i,j});}
                        else if(i<grid.size()-1 && grid[i+1][j] == 2){flag = false;v.push_back({i,j});}
                        else if(j>0 && grid[i][j-1] == 2){flag = false;v.push_back({i,j});}
                        else if(j<grid[i].size()-1 && grid[i][j+1] == 2){flag = false;v.push_back({i,j});}
                    }
                }
            }
            if(flag) break;
            for(int i = 0;i<v.size();i++){
                grid[v[i][0]][v[i][1]] = 2;
            }
            ans++;
        }
        for(int i = 0;i<grid.size();i++){
                for(int j = 0;j<grid[i].size();j++){
                    if(grid[i][j] == 1){
                        return -1;
                    }
                }
            }
        return ans;
    }
};