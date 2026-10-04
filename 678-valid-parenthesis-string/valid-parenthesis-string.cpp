class Solution {
public:int dp[101][101];
    bool solve(string &s,int i,int noo){
        if(noo < 0 || noo > s.size())return 0;
        if(i >= s.size()){
            return noo == 0;
        }
        if(dp[i][noo] != -1)return dp[i][noo];
        if(s[i] == '*'){
            return dp[i][noo] = (solve(s,i+1,noo+1) || solve(s,i+1,noo-1) || solve(s,i+1,noo));
        }
        if(s[i] == '('){
            return dp[i][noo] = solve(s,i+1,noo+1);
        }
        return dp[i][noo] = solve(s,i+1,noo-1);
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,0);
    }
};