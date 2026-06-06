class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& m) {
        int a = m.size(), b = m[0].size();
        unordered_set<int> st;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (m[i][j] != 0)
                    st.insert(m[i][j]);
            }
        }
        // building a matrix which stores if there is a greater value than the
        // element or not.
        unordered_map<int, vector<vector<int>>> mp;
        for (auto p : st) {
            mp[p] = vector<vector<int>>(a, vector<int>(b, 0));
            auto& k = mp[p];
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    if (m[i][j] > p)
                        k[i][j] = 1;
                    if (j > 0)
                        k[i][j] += k[i][j - 1]; // prefix sum
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (m[i][j] == 0)
                    continue;
                int ele = m[i][j];
                auto& k = mp[ele];
                int up = max(0, i - ele);
                int down = min(a - 1, i + ele);
                int l = max(0, j - ele);
                int r = min(b - 1, j + ele);
                bool f = true;
                int L = l, R = r;
                for (int row = up; row <= down && f; row++) {
                    l = L;
                    r = R;
                    if (row == up) {
                        if (i - up == ele && j - l == ele)
                            l++;
                        if (i - up == ele && r - j == ele)
                            r--;
                    }
                    if (row == down) {
                        if (down - i == ele && j - l == ele)
                            l++;
                        if (down - i == ele && r - j == ele)
                            r--;
                    }
                    int x = k[row][r];
                    if (l > 0)
                        x -= k[row][l - 1];

                    if (x > 0)
                        f = false;
                }
                if (f)
                    ans++;
            }
        }
        return ans;
    }
};