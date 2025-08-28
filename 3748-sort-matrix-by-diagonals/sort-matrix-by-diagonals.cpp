class Solution {
public:
    int n;
    vector<int> decreasing(int i, int j, vector<vector<int>>& grid) {
        j = 0;
        vector<int> v;
        while (i < n) {
            v.push_back(grid[i][j]);
            i++;
            j++;
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        return v;
    }
    vector<int> increasing(int i, int j, vector<vector<int>>& grid) {
        i = 0;
        vector<int> v;
        while (j < n) {
            v.push_back(grid[i][j]);
            i++;
            j++;
        }
        sort(v.begin(), v.end());
        return v;
    }
    void fill_left(vector<vector<int>>& ans, int i, int j, vector<int>& v) {
        j = 0;
        int k = 0;
        while (i < n) {
            ans[i][j] = v[k];
            i++;
            j++;
            k++;
        }
        return;
    }
    void fill_right(vector<vector<int>>& ans, int i, int j, vector<int>& v) {
        i = 0;
        int k = 0;
        while (j < n) {
            ans[i][j] = v[k];
            i++;
            j++;
            k++;
        }
        return;
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = n-1; i >= 0; i--) {
            vector<int> v = decreasing(i, i, grid);
            fill_left(ans, i, i, v);
        }
        for (int j = 1; j < n; j++) {
            vector<int> v = increasing(j, j, grid);
            fill_right(ans, j, j, v);
        }
        return ans;
    }
};