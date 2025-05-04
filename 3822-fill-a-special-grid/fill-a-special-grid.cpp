class Solution {
public:
    void fill(vector<vector<int>>& v, int &i, int N, int row, int col) {
        if (N == 0) {
            v[row][col] = i++;
            return;
        }

        int len = pow(2, N - 1); // side length of each quadrant

        // Fill quadrants in the required order to satisfy conditions:
        fill(v, i, N - 1, row, col + len);       // Top-right
        fill(v, i, N - 1, row + len, col + len); // Bottom-right
        fill(v, i, N - 1, row + len, col);       // Bottom-left
        fill(v, i, N - 1, row, col);             // Top-left
    }

    vector<vector<int>> specialGrid(int N) {
        int n = pow(2, N); // size of the grid
        vector<vector<int>> v(n, vector<int>(n));
        int i = 0;
        fill(v, i, N, 0, 0); // start filling from top-left corner
        return v;
    }
};
