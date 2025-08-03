class Solution {
public:
    long long maxSumTrionic(vector<int>& v) {
        int n = v.size();
        int idx = 0;
        long long ans = LLONG_MIN;

        while (idx < n - 3) {
            // Step 1: First strictly increasing segment [l...p]
            int l = idx;
            int p = l, q;
            long long first_increasing = v[p];

            while (p < n - 1 && v[p] < v[p + 1]) {
                p++;
                first_increasing += v[p];
                if (v[p] > first_increasing && p < n - 1 && v[p] < v[p + 1])
                    first_increasing = v[p]; // Reset sum if better start found (your logic)
            }

            if (p >= n - 2 || p == l) {
                idx++;
                continue; // Not enough room or no initial increase
            }

            // Step 2: Strictly decreasing segment [p...q]
            q = p + 1;
            if (v[q] >= v[p]) {
                idx++;
                continue; // Not a valid decreasing start
            }

            long long decreasing = v[q];
            while (q < n - 1 && v[q] > v[q + 1]) {
                q++;
                decreasing += v[q]; // Accumulate strictly decreasing values
            }

            if (q == n - 1) {
                idx++;
                continue; // No room left for final increase
            }

            // Step 3: Second strictly increasing segment [q...r]
            long long second_increasing = 0;
            int r = q, j = r;

            while (r < n - 1 && v[r] < v[r + 1]) {
                r++;
                second_increasing += v[r];
                if (v[r] < 0 && r < n - 1 && v[r] < v[r + 1])
                    j = r; // Smart skip marker if stuck in a negative slope

                ans = max(ans, first_increasing + decreasing + second_increasing);
            }

            if (r == q) {
                idx++;
                continue; // No second increase occurred
            }

            idx = j; // Progress forward (your skip strategy)
        }

        return ans;
    }
};
