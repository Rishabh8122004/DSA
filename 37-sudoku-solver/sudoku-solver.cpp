class Solution {
public:
    vector<vector<int>> grid_num = vector<vector<int>>(9, vector<int>(9, 0));
    vector<unordered_map<char, int>> row = vector<unordered_map<char, int>>(9);
    vector<unordered_map<char, int>> col = vector<unordered_map<char, int>>(9);
    vector<unordered_map<char, int>> grid = vector<unordered_map<char, int>>(9);
    bool solve(vector<vector<char>>& b, int r, int c) {
        if (r == 9)
            return true;
        if (c == 9) {
            return solve(b, r + 1, 0);
        }
        if (b[r][c] != '.') {
            return solve(b, r, c + 1);
        } else if (b[r][c] == '.') {
            for (char dig = '1'; dig <= '9'; dig++) {
                if (row[r][dig] == 1 || col[c][dig] == 1 || grid[grid_num[r][c]][dig] == 1)
                    continue;
                else {
                    row[r][dig] = 1;
                    col[c][dig] = 1;
                    grid[grid_num[r][c]][dig] = 1;
                    b[r][c] = dig;
                    if (solve(b, r, c + 1)) {
                        return true;
                    } else {
                        row[r][dig] = 0;
                        col[c][dig] = 0;
                        grid[grid_num[r][c]][dig] = 0;
                        b[r][c] = '.';
                    }
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& b) {
        int g = 0;
        for (int i = 0; i <= 6; i += 3) {
            for (int j = 0; j <= 6; j += 3) {
                for (int r = j + 0; r < j + 3; r++) {
                    for (int c = i + 0; c < i + 3; c++) {
                        grid_num[r][c] = g;
                        if (b[r][c] == '.')
                            continue;
                        char x = b[r][c];
                        row[r][x]++;
                        col[c][x]++;
                        grid[g][x]++;
                    }
                }
                g++;
            }
        }
        solve(b, 0, 0);
        return;
    }
};