class Solution {
public:
    int n;
    int overlap(vector<vector<int>>& a, vector<vector<int>>& b, int r_offset,int c_offset) {
        int s = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int b_i = i+r_offset;
                int b_j = j+c_offset;
                if(b_i<0 || b_i>=n || b_j <0 || b_j >=n || a[i][j] == 0)continue;
                if(a[i][j] == b[b_i][b_j])s++;
            }
        }
        return s;
    } 
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
    int ans = 0;
    n = a.size();
    for (int r_offset = -n + 1; r_offset <= n - 1; r_offset++) {
        for (int c_offset = -n + 1; c_offset <= n - 1; c_offset++) {
            ans = max(ans, overlap(a, b, r_offset, c_offset));
        }
    }
    return ans;
}
}
;