class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int n = w1.size();
        vector<int>dp(n+1,0);
        int m = w2.size();
        if(m == 1)return {0};
        for(int i = n-1;i>=0;i--){
            dp[i] = dp[i+1];
            if((dp[i+1]<m) && (w1[i] == w2[m-dp[i+1]-1])){
                dp[i] += 1;
            }
        }
        vector<int>ans;
        int c = 1;
        int j = 0;
        for(int i = 0;i<n;i++){
            //cout<<dp[i]<<' ';
            if(w1[i] == w2[j]){
                ans.push_back(i);
                j++;
            }
            else{
                if((c == 1) && (dp[i+1] >= m-1-j)){
                    ans.push_back(i);
                    j++;
                    c = 0;
                }
            }
            if(j == m)return ans;
        }
        return {};
    }
};