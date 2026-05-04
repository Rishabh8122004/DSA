class Solution {
public:
    void rotate(vector<vector<int>>& m) {
         int n = m.size();

        // Transpose the matrix
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                swap(m[i][j], m[j][i]);
            }
        }

        // Reverse each row
        for(int i = 0; i < n; i++)
        {
            reverse(m[i].begin(), m[i].end());
        }
    }
};