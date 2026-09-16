class Solution {
public:
    int m = 1e9+7;
    vector<vector<long long>>dp;
    long long solve(int i,int &n,int k){
        if(k == 0)return dp[i][k] = 1;
        if(i == n){
            return dp[i][k] = 0;
        }
        if(dp[i][k] != -1)return dp[i][k];
        long long ways = 0;
        for(int j = i+1;j<=n-k;j++){
            ways = (ways + solve(j,n,k-1))%m;
        }
        ways = (ways + solve(i+1,n,k))%m;
        return dp[i][k] = ways;
    }
    int numberOfSets(int n, int k) {
        dp.resize(n+1,vector<long long>(k+1,-1));
        return solve(0,n,k);
    }
};