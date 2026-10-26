class Solution {
public:
    int n, m;
    bool solve(int i, int j, vector<vector<int>>& g, int& sum) {
        if (i == n || i < 0 || j == m || j < 0)
            return false;
        if (g[i][j] == 0)
            return true;
        sum += 1;
        g[i][j] = 0;
        bool up = solve(i - 1, j, g, sum);
        bool right = solve(i, j + 1, g, sum);
        bool down = solve(i + 1, j, g, sum);
        bool left = solve(i, j - 1, g, sum);
        return (up && right && down && left);
    }
    int numEnclaves(vector<vector<int>>& g) {
        n = g.size();
        m = g[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) {
                    int sum = 0;
                    ans += (solve(i, j, g, sum) == true ? sum : 0);
                    cout<<i<<" "<<j<<" "<<sum<<endl;
                }
            }
        }
        return ans;
    }
};