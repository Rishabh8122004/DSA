class Solution {
public:
    string s;
    long long dp[20][10][2]; // pos(0-15) , last(0-9), tight(0 - 1)
    int path[16];
    long long solve(int i,int last,bool tight){
        if(i == 16)return 1;
        if(dp[i][last][tight] != -1)return dp[i][last][tight];
        int limit = (tight?s[i]-'0':9);
        long long ans = 0;
        for(int d = 0; d <= limit; d++){
            if(path[i] == 1 && d<last)continue;
            ans += solve(i+1,(path[i] == 1?d:last),(tight && (d == (s[i]-'0'))));
        }
        return dp[i][last][tight] = ans;
    }
    long long countGoodIntegersOnPath(long long l, long long r, string d) {
        memset(path,0,sizeof(path));
        memset(dp,-1,sizeof(dp));
        int j = 0;
        path[0] = 1;
        for(int i = 0;i<d.size();i++){
            if(d[i] == 'D')j+=4;
            else j++;
            path[j] = 1;
        }
        l-=1;
        s = to_string(l);
        while(s.size()<16)s = '0'+s;
        long long left = solve(0,0,true); // pos , last , tight = true(0 pos is in the path)
        s = to_string(r);
        while(s.size()<16)s = '0'+s;
        memset(dp,-1,sizeof(dp));
        long long right = solve(0,0,true);
        return right-left;
    }
};