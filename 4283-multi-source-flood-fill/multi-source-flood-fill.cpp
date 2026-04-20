class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& s) {
        vector<vector<int>> v(n, vector<int>(m));
        queue<vector<int>> q;
        for (int i = 0; i < s.size(); i++) {
            v[s[i][0]][s[i][1]] = s[i][2];
            swap(s[i][0], s[i][2]);
        }
        sort(s.begin(), s.end());
        for (int i = s.size()-1; i >= 0; i--) {
            q.push(s[i]);
        }
        while (!q.empty()) {
            auto p = q.front();
            int i = p[2], j = p[1], c = p[0];
            q.pop();
            if (i > 0 && v[i - 1][j] == 0) {
                v[i-1][j] = c;
                q.push({c,j,i-1});
            }  if (i < v.size() - 1 && v[i + 1][j] == 0) {
                v[i+1][j] = c;
                q.push({c,j,i+1});
            }  if (j > 0 && v[i][j - 1] == 0) {
                v[i][j-1] = c;
                q.push({c,j-1,i});
            }  if (j < v[i].size() - 1 && v[i][j + 1] == 0) {
                v[i][j+1] = c;
                q.push({c,j+1,i});
            }
        }
        return v;
    }
};