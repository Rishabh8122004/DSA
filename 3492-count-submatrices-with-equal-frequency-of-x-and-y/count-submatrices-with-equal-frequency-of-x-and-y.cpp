class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& g) {
        int n = g.size(),m = g[0].size();
        vector<vector<pair<int,int>>>v(n,vector<pair<int,int>>(m));
        int x,y;
        for(int j = 0;j<m;j++){ // column wise prefix calculation of number of x and y
            x = 0;y = 0;
            for(int i = 0;i<n;i++){
                if(g[i][j] == 'X')x++;
                else if(g[i][j] == 'Y')y++;
                v[i][j] = {x,y};
            }
        }
        // row wise iteration
        int ans = 0;
        for(int i = 0;i<n;i++){
            x = 0;y = 0;
            for(int j = 0;j<m;j++){
                x += v[i][j].first;
                y += v[i][j].second;
                if(x == y && x>0)ans++;
            }
        }
        return ans;
    }
};