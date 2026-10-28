class Solution {
public:
    int minCost(vector<vector<int>>& g) {
        int n = g.size(),m = g[0].size();
        vector<vector<bool>> dp_prev(m, vector<bool>(1024, false));
        dp_prev[0][g[0][0]] = 1;
        for(int i = 0;i<n;i++){
            vector<vector<bool>> dp_curr(m, vector<bool>(1024, false));

            if (i > 0) {
                for (int k = 0; k < 1024; k++) {
                    if (dp_prev[0][k]) {
                        dp_curr[0][k ^ g[i][0]] = true;
                    }
                }
            } else {
                dp_curr[0][g[0][0]] = true;
            }

            for(int j = 0;j<m;j++){
                if(i == 0 && j == 0)continue;
                for(int k = 0;k<1024;k++){
                    if(i-1 >= 0){
                        if (dp_prev[j][k]) {
                            dp_curr[j][k ^ g[i][j]] = true;
                        }
                    }
                    if(j-1 >= 0){
                        if (dp_curr[j - 1][k]) {
                            dp_curr[j][k ^ g[i][j]] = true;
                        }
                    }
                }
            }
            if(i == 0)dp_curr[0][g[0][0]] = true;
            dp_prev = dp_curr;
        }
        for(int k = 0;k<1024;k++){
            if(dp_prev[m-1][k] == true)return k;
        }
        return 0;
    }
};