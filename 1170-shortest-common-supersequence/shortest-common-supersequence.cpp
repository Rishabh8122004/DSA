class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(),m = str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        if(str1 == str2)return str1;
        // string a = lcs(0,0,str1,str2,dp);
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string a = "";
        int i = n,j = m;
        while(i>0 && j>0){
            if(dp[i][j] == dp[i-1][j]){
               i--; 
            }
            else if(dp[i][j] == dp[i][j-1])j--;
            else if(dp[i][j] == dp[i-1][j-1] + 1){
                a += str1[i-1];
                i--;j--;
            }
        }
        reverse(a.begin(),a.end());
        string ans = "";
        i = 0;j = 0;
        int k = 0;
        while(i<str1.size() || j < str2.size()){
            if(k>=a.size()){
                while(i<str1.size()){
                    ans+=str1[i];
                    i++;
                }
                while(j<str2.size()){
                    ans+=str2[j];
                    j++;
                }
                break;
            }
            if(a[k] != str1[i]){
                ans += str1[i];
                i++;
            }
            if(a[k] != str2[j]){
                ans += str2[j];
                j++;
            }
            if(a[k] == str1[i] && a[k] == str2[j]){
                ans+=str1[i];
                k++;j++;i++;
            }
        }
        return ans;
    }
};