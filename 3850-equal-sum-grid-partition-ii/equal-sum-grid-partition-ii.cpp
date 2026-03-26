class Solution {
public:
    bool is_connected(const vector<pair<int,int>>& v, int val,
                      int r1, int r2, int c1, int c2) {
        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;

        for (int i = 0; i < (int)v.size(); i++) {
            int r = v[i].first;
            int c = v[i].second;

            // cell must lie inside the chosen rectangle
            if (r < r1 || r > r2 || c < c1 || c > c2) continue;

            // if rectangle has only one cell, removing it makes it empty
            if (rows == 1 && cols == 1) return false;

            // single row -> only endpoints are allowed
            if (rows == 1) {
                if (c == c1 || c == c2) return true;
            }
            // single column -> only endpoints are allowed
            else if (cols == 1) {
                if (r == r1 || r == r2) return true;
            }
            // proper rectangle -> removing any one cell keeps it connected
            else {
                return true;
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        long long total = 0, curr = 0;

        // safer than vector<vector<pair<int,int>>> v(100005)
        unordered_map<int, vector<pair<int,int>>> v;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v[g[i][j]].push_back({i, j});
                total += g[i][j];
            }
        }

        // ---------------- Horizontal cuts ----------------
        curr = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                curr += g[i][j];
            }

            // exact equal split
            if (2LL * curr == total) return true;

            // top is smaller -> need to remove from bottom
            if (2LL * curr < total) {
                long long diff = total - 2LL * curr;
                if (diff <= INT_MAX && v.count((int)diff)) {
                    // bottom rectangle = rows [i+1 ... n-1], cols [0 ... m-1]
                    if (is_connected(v[(int)diff], (int)diff, i + 1, n - 1, 0, m - 1)) {
                        return true;
                    }
                }
            }
            // top is bigger -> need to remove from top
            else {
                long long diff = 2LL * curr - total;
                if (diff <= INT_MAX && v.count((int)diff)) {
                    // top rectangle = rows [0 ... i], cols [0 ... m-1]
                    if (is_connected(v[(int)diff], (int)diff, 0, i, 0, m - 1)) {
                        return true;
                    }
                }
            }
        }

        // ---------------- Vertical cuts ----------------
        curr = 0;
        for (int j = 0; j < m - 1; j++) {
            for (int i = 0; i < n; i++) {
                curr += g[i][j];
            }

            // exact equal split
            if (2LL * curr == total) return true;

            // left is smaller -> need to remove from right
            if (2LL * curr < total) {
                long long diff = total - 2LL * curr;
                if (diff <= INT_MAX && v.count((int)diff)) {
                    // right rectangle = rows [0 ... n-1], cols [j+1 ... m-1]
                    if (is_connected(v[(int)diff], (int)diff, 0, n - 1, j + 1, m - 1)) {
                        return true;
                    }
                }
            }
            // left is bigger -> need to remove from left
            else {
                long long diff = 2LL * curr - total;
                if (diff <= INT_MAX && v.count((int)diff)) {
                    // left rectangle = rows [0 ... n-1], cols [0 ... j]
                    if (is_connected(v[(int)diff], (int)diff, 0, n - 1, 0, j)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};