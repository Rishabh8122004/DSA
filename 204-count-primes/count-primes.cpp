class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        int p = 2;
        if(n == 0 || n == 1) return 0;
        vector<bool> v(n, true);
        int a = sqrt(n);
        while (p <= a) {
            if (v[p]){
                for (int j = 2*p; j < n; j+=p) {
                    v[j] = false;
                }
            }
            p++;
        }
        for (int i = 2; i < v.size(); i++) {
            if (v[i])
                ans++;
        }
        return ans;
    }
};