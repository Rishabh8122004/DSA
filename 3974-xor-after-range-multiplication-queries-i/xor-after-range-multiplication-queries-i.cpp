class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int mod = 1000000007;
        for (int i = 0; i < q.size(); i++) {
            int l = q[i][0],r = q[i][1],k = q[i][2],v = q[i][3];
            int idx = l;
            while (idx <= r) {
                nums[idx] = ((long)nums[idx] * v) % (mod);
                idx += k;
            }
        }
        int x = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            x = x ^ nums[i];
        }
        return x;
    }
};