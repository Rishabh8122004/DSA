class Solution {
public:
    string s;
    int dp[11][2][1<<10][2]; // added started

    int solve(int i, bool tight, int mask, bool started){
        if(i == s.size()) return started; // count only valid numbers (>0)

        if(dp[i][tight][mask][started] != -1)
            return dp[i][tight][mask][started];

        int limit = (tight ? s[i] - '0' : 9);
        int ans = 0;

        for(int d = 0; d <= limit; d++){

            bool new_tight = (tight && d == (s[i] - '0'));

            // Case 1: still leading zeros
            if(!started && d == 0){
                ans += solve(i+1, new_tight, mask, 0);
            }
            else{
                // digit already used
                if(mask & (1 << d)) continue;

                ans += solve(i+1, new_tight, mask | (1<<d), 1);
            }
        }

        return dp[i][tight][mask][started] = ans;
    }

    int countSpecialNumbers(int n) {
        memset(dp, -1, sizeof(dp));
        s = to_string(n);
        return solve(0, 1, 0, 0);
    }
};