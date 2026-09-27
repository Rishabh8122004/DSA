class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        auto a = b;
        int m = a.size(), n = a[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                if ((i - 1 >= 0) && (j - 1 >= 0)) {
                    count += b[i - 1][j - 1];
                }
                if (i - 1 >= 0) {
                    count += b[i - 1][j];
                }
                if (j - 1 >= 0)
                    count += b[i][j - 1];
                if ((i - 1 >= 0) && (j + 1 < n))
                    count += b[i - 1][j + 1];
                if (j + 1 < n)
                    count += b[i][j + 1];
                if ((i + 1 < m) && (j + 1 < n))
                    count += b[i + 1][j + 1];
                if (i + 1 < m)
                    count += b[i + 1][j];
                if ((i + 1 < m) && (j - 1 >= 0)) {
                    count += b[i + 1][j - 1];
                }
                if (b[i][j] == 1) {
                    if (count < 2 || count > 3)
                        a[i][j] = 0;
                } else {
                    if (count == 3)
                        a[i][j] = 1;
                }
            }
        }
        b = a;
        return;
    }
};