class Solution {
public:
    int mod = 1000000007;

    long long get_power(long long x){
        long long res = 1, base = 2;
        while(x){
            if(x & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            x >>= 1;
        }
        return res;
    }

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();

        vector<pair<int,int>> v;
        long long last = 0;

        // separate zero-free segments
        for(int i = 0; i < n; i++){
            if(nums0[i] == 0){
                last += nums1[i];
            } else {
                v.push_back({nums1[i], nums0[i]});
            }
        }

        // same sorting logic as working code
        sort(v.begin(), v.end(), [](pair<int,int>& a, pair<int,int>& b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });

        long long ans = 0;
        long long exp = 0;

        // iterate from back (as in working code)
        for(int i = (int)v.size() - 1; i >= 0; i--){
            long long ones = v[i].first;
            long long zeros = v[i].second;

            exp += zeros;

            long long val = (get_power(exp) * ((get_power(ones) - 1 + mod) % mod)) % mod;
            ans = (ans + val) % mod;

            exp += ones;
        }

        // add all zero-free segments at the end
        if(last > 0){
            long long val = (get_power(exp) * ((get_power(last) - 1 + mod) % mod)) % mod;
            ans = (ans + val) % mod;
        }

        return ans;
    }
};