class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int mod = 1000000007;
        for (int i = 0; i < q.size(); i++) {
            int idx = q[i][0];
            while (idx <= q[i][1]) {
                nums[idx] = ((long)nums[idx] * q[i][3]) % (mod);
                idx += q[i][2];
            }
        }
        int x = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            x = x ^ nums[i];
        }
        return x;
    }
};