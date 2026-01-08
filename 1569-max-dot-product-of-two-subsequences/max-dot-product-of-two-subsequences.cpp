class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MIN));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                dp[i][j] = nums1[i-1]*nums2[j-1];
                long x = ((long)nums1[i-1]*nums2[j-1])+(long)dp[i-1][j-1];
                if(x>dp[i][j])dp[i][j] = x;
                dp[i][j] = max(dp[i][j],max(dp[i][j-1],dp[i-1][j]));
            }
        }
        return dp[n][m];
    }
};