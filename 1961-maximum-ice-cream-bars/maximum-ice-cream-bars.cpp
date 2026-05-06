class Solution {
public:
    int maxIceCream(vector<int>& c, int coins) {
        int n = c.size();
        int m = c[0];
        for(int i = 1;i<n;i++){
            m = max(m,c[i]);
        }
        vector<int>f(m+1);
        for(int i = 0;i<n;i++)f[c[i]]++;
        int ans = 0;
        for(int i = 1;i<f.size();i++){
            if(coins<i)break;
            m = coins/i;
            if(m>f[i])m = f[i];
            ans += m;
            coins -= (m*i);
        }
        return ans;
    }
};