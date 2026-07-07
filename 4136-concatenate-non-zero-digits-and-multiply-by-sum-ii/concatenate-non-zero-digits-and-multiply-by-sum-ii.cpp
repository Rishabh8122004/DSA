class Solution {
public:
    long long mod = 1e9 + 7;
    long long y = 1;
    int solve(vector<long long>& pref_digit, vector<long long>& pref_sum,int& l, int& r,long long *po) {
        long long left, right;
        right = pref_digit[r];
        left = (((l>0?pref_digit[l-1]:0)*po[r-l+1]))%mod;
        right = (right-left+mod)%mod;
        return (right * (pref_sum[r] - (l > 0 ? pref_sum[l - 1] : 0))) % mod;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& q) {
        int m = s.size();
        vector<int> v(m, 0); // no. of zeros occured till this index 'i'
        string z = "";
        for (int i = 0; i < m; i++) {
            if (s[i] == '0') {
                v[i] += 1;
            } else {
                z += s[i];
            }
            if (i > 0)
                v[i] += v[i - 1];
        }
        m = z.size();
        vector<long long> pref_digit(m), pref_sum(m, 0);
        long long po[m+5];
        // calculating powers of 10 :
        for (int i = 0; i < m+5; i++) {
            po[i] = y;
            y *= 10;
            y %= mod;
        }
        long long sum = 0;
        long long x = 0;
        for (int i = 0; i < m; i++) { // calculating prefix of digits and sum
            x = (x * 10 + (z[i] - '0')) % mod;
            sum += (z[i] - '0');
            pref_digit[i] = x;
            pref_sum[i] = sum;
        }

        int l, r;
        vector<int> ans;
        for (int i = 0; i < q.size(); i++) {
            l = q[i][0];
            r = q[i][1];
            r -= (v[r]);
            l -= (l > 0 ? v[l - 1] : 0);
            if (l > r) {
                ans.push_back(0);
                continue;
            }
            ans.push_back(solve(pref_digit, pref_sum, l, r,po));
        }
        return ans;
    }
};