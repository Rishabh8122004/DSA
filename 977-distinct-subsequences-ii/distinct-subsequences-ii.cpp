class Solution {
public:
    int mod = 1e9+7;
    int dp[2001];
    vector<int>prev;
    int solve(int n){
        if(n == 0){
            return 1;//empty ""
        }
        if(dp[n] != -1)return dp[n];
        
        int total = (2 * solve(n-1))%mod;

        int duplicate = 0;
        if(prev[n] != 0){
            duplicate = solve(prev[n]-1);
        }

        return dp[n] = (total-duplicate + mod)%mod;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        prev.assign(n+1,0);
        vector<int>lastseen(26,0);
        for(int i = 1;i<=n;i++){
            int c = s[i-1]-'a';
            prev[i] = lastseen[c];
            lastseen[c] = i;
        }
        return (solve(n)-1+mod)%mod;
    }
};