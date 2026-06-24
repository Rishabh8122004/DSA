class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        r = r-l+1;
        l = 1;
        typedef long long ll;
        ll mod = 1e9+7;
        static long long dp[2002][2002][2];
        memset(dp,0,sizeof(dp));
        bool inc = false;

        // base case is that all the arrays of size 'n' are considered as zig zag

        for(int prev = 1;prev<=r;prev++){
            dp[n][prev][0] = 1; // base case
            dp[n][prev][1] = 1;
        }
        vector<vector<long long>>cumulative_sum(r+1,vector<long long>(2,0));
        
        for(int i = n-1;i>=0;i--){
            //prefix sum
            for(int prev = 1;prev<=r;prev++){
                cumulative_sum[prev][1] = (dp[i+1][prev][1]+cumulative_sum[prev-1][1])%mod;
                cumulative_sum[prev][0] = (dp[i+1][prev][0]+cumulative_sum[prev-1][0])%mod;
            }
            for(int prev = 1;prev<=r;prev++){

                // increasing 
                dp[i][prev][1] = (cumulative_sum[r][0]-cumulative_sum[prev][0]+mod)%mod;

                // for(int next = prev+1;next <= r;next++){
                //     dp[i][prev][1] = ((dp[i][prev][1]+dp[i+1][next][0])%mod);
                // }

                // decreasing
                dp[i][prev][0] = (cumulative_sum[prev-1][1]-cumulative_sum[0][1]+mod)%mod;
                
                // for(int next = 1;next<prev;next++){
                //     dp[i][prev][0] = ((dp[i][prev][0]+dp[i+1][next][1])%mod);
                // }
            }
        }
        ll result=0;
        for(int startVal = 1;startVal<=r;startVal++){
            result = (result + dp[1][startVal][1])%mod;

            result = (result + dp[1][startVal][0])%mod;
        }
        return result;
    }
};