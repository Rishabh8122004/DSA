class Solution {
public:
    int findLength(vector<int>& n1, vector<int>& n2) {
        int ans = 0;
        /* using a 4D vector
        vector<vector<vector<vector<int>>>> v(101, vector<vector<vector<int>>>(1001));
        for(int i = 0;i<n2.size();i++){
            vector<int>q;
            for(int j = i;j<n2.size();j++){
                q.push_back(n2[j]);
                v[q[0]][q.size()].push_back(q);
            }
        }
        for(int i = 0;i<n1.size();i++){
            vector<int>q;
            for(int j = i;j<n1.size();j++){
                q.push_back(n1[j]);
                bool flag = false; // not found
                // now we gonna search this subarray into the created vector of subarrays
                for(int k = 0;k<v[q[0]][q.size()].size();k++){
                    if(q == v[q[0]][q.size()][k])if(ans<q.size())ans = q.size();
                }
            }
        }*/
        int n = n1.size(),m = n2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int i = 1;i<=n;i++){
            dp[0][i] = n1[i-1];
        }
        for(int j = 1;j<=m;j++){
            dp[j][0] = n2[j-1];
        }
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(i == 1 || j == 1){
                    if(dp[0][j] == dp[i][0]){dp[i][j] = 1;}
                }
                else{dp[i][j] = ((dp[0][j] == dp[i][0])?(1+dp[i-1][j-1]):0);}
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};