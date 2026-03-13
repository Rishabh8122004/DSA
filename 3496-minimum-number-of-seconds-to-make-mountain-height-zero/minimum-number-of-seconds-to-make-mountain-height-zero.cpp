class Solution {
public:

    // Checks if it is possible to reduce the mountain height to 0
    // within 'mid' seconds.
    bool is_valid(long mid, int h, vector<int>& wt) {

        for (int i = 0; i < wt.size(); i++) {

            int j = 1;

            /*
            Each worker reduces height sequentially:
            1st unit -> wt[i] * 1 seconds
            2nd unit -> wt[i] * 2 seconds
            3rd unit -> wt[i] * 3 seconds
            ...

            Total time after j operations =
            wt[i] * (1 + 2 + ... + j)
            = wt[i] * j*(j+1)/2
            */

            while (wt[i] * ((1LL * j * (j + 1)) / 2) <= mid) {

                if (h <= 0) return true;   // already completed

                h--;  // worker removes one height unit
                j++;  // move to next operation
            }

            if (h <= 0) return true;
        }

        /*
        Optimization (O(1) instead of linear loop):

        From the condition:
            wt[i] * j(j+1)/2 <= mid

        Solve quadratic:
            j^2 + j <= 2*mid / wt[i]

        Maximum j can be computed directly using:

            long long j = (-1 + sqrt(1 + 8 * mid / wt[i])) / 2;
            h -= j;

        This replaces the inner loop and improves performance.
        */

        return h <= 0;
    }

    long long minNumberOfSeconds(int h, vector<int>& wt) {

        sort(wt.begin(), wt.end());

        /*
        Upper bound:
        If the fastest worker does all the work alone.
        Time = wt[0] * (1 + 2 + ... + h)
             = wt[0] * h*(h+1)/2
        */

        long ans = wt[0] * ((1LL * h * (h + 1)) / 2);

        long lo = 1, hi = ans;

        // Binary search on time
        while (lo <= hi) {

            long mid = lo + (hi - lo) / 2;

            if (is_valid(mid, h, wt)) {
                ans = min(ans, mid);
                hi = mid - 1;     // try smaller time
            }
            else {
                lo = mid + 1;     // need more time
            }
        }

        return ans;
    }
};