class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& g, int k) {
        int n = g.size();
        int m = g[0].size();
        int l = 0, r = m - 1, u = 0, d = n - 1, i, j, K;
        vector<int>q;
        while ((l <= r - 1) && (u <= d - 1)) {
            // filling the queue
            i = l;
            j = u;

            while (j < d) { // left
                q.push_back(g[j][i]);
                j++;
            }

            while (i < r) { // bottom
                q.push_back(g[j][i]);
                i++;
            }

            while (j > u) { // right
                q.push_back(g[j][i]);
                j--;
            }

            while (i > l) { // top
                q.push_back(g[j][i]);
                i--;
            }
            // rotating
            K = k % q.size();
            int idx = 0,len = q.size();
            // filling the grid
            i = l, j = u;

            while (j < d) {
                g[j][i] = q[(idx-K + len)%len];
                idx++;
                j++;
            }

            while (i < r) {
                g[j][i] = q[(idx-K + len)%len];
                idx++;
                i++;
            }

            while (j > u) {
                g[j][i] = q[(idx-K + len)%len];
                idx++;
                j--;
            }

            while (i > l) {
                g[j][i] = q[(idx-K + len)%len];
                idx++;
                i--;
            }
            l++;
            r--;
            u++;
            d--;
            q.clear();
        }
        return g;
    }
};