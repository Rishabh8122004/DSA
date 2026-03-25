class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& g) {
        int n = g.size(),m = g[0].size();
        long total = 0,cur = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                total += g[i][j]; 
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cur+=g[i][j];
                if(2*cur == total && j == m-1)return true;
            }
        }
        cur = 0;
        for(int j = 0;j<m;j++){
            for(int i = 0;i<n;i++){
                cur += g[i][j];
                if(2*cur == total && i == n-1)return true;
            }
        }
        return false;
    }
};