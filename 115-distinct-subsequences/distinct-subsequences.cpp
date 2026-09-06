class Solution {
public:
    int dp[1001][1001];
    int n,m;
    string s,t;
    int solve(int i,int j){
        if(j == m)return dp[i][j] = 1;
        if(i == n)return dp[i][j] = 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = (solve(i+1,j+1) + solve(i+1,j));
        }
        return dp[i][j] = solve(i+1,j);
    }
    int numDistinct(string S, string T) {
        s = S;t = T;
        if(s.size()<=t.size())return (s == t);
        n = s.size();m = t.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};