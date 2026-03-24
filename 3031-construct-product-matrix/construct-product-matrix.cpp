class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& g) {
        int n = g.size(),m = g[0].size();
        vector<long long>suff(n*m),preff(n*m);
        int mod = 12345;
        int k = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0 && j == 0)suff[k] = g[i][j];
                else{
                    if(j == 0)suff[k] = g[i][j]*suff[k-1];
                    else suff[k] = g[i][j]*suff[k-1];
                }
                suff[k]%=mod;
                k++;
            }
        }
        k=(n*m)-1;
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(i == n-1 && j == m-1)preff[k] = g[i][j];
                else{
                    if(j == m-1)preff[k] = g[i][j]*preff[k+1];
                    else preff[k] = g[i][j]*preff[k+1];
                }
                preff[k]%=mod;
                k--;
            }
        }
        k = 0;
        vector<vector<int>>v(n,vector<int>(m));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                v[i][j] = ((i == 0&& j== 0)?(preff[k+1]%mod):((i == n-1 && j == m-1)?(suff[k-1]%mod):(suff[k-1]*preff[k+1])%mod));
                k++;
            }
        }
        return v;
    }
};