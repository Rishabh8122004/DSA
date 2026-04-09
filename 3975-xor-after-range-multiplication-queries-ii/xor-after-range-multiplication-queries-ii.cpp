class Solution {
public:
    long long mod = 1000000007;

    long long power(long long a, long long b) {
        long long ans = 1;
        a %= mod;
        while (b > 0) {
            if (b & 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        map<int, vector<vector<int>>> mp;

        for (int i = 0; i < q.size(); i++) {
            int l = q[i][0], r = q[i][1], k = q[i][2], v = q[i][3];

            if (k <= sqrt(n)) {
                mp[k].push_back({l, r, v});
            }
            else {
                while (l <= r) {
                    nums[l] = (1LL * nums[l] * v) % mod;
                    l += k;
                }
            }
        }

        for (auto p : mp) {
            int k = p.first;
            vector<vector<int>> v = p.second;
            vector<long long> diff_array(n + 1, 1);

            for (int i = 0; i < v.size(); i++) {
                int l = v[i][0], r = v[i][1], prod = v[i][2];
                int no_of_steps = (r - l) / k;
                int next = l + (no_of_steps + 1) * k;

                diff_array[l] = (diff_array[l] * prod) % mod;
                if (next < n) diff_array[next] = (diff_array[next] * power(prod, mod - 2)) % mod;
            }

            for (int start = 0; start < k; start++) {
                long long cur = 1;
                for (int i = start; i < n; i += k) {
                    cur = (cur * diff_array[i]) % mod;
                    nums[i] = (1LL * nums[i] * cur) % mod;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};