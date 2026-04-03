class Solution {
public:
    int lower_bound_custom(vector<int>& w, int target) {
        int lo = 0, hi = w.size() - 1;
        int ans = w.size(); // by default ,if not found
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (w[mid] >= target) {
                ans = mid;    // possible ans
                hi = mid - 1; // try smaller index
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
    int upper_bound_custom(vector<int>& w, int target) {
        int lo = 0, hi = w.size() - 1;
        int ans = w.size();

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (w[mid] > target) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
    int maxWalls(vector<int>& r, vector<int>& d, vector<int>& w) {
        int n = r.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {r[i], d[i]};
        }
        sort(v.begin(), v.end());
        sort(w.begin(), w.end());
        vector<int> L(n), R(n); // no of left and right walls robot[i] can
                                // destroy respectively.
        vector<int> Overlap(n); // two adjacent robots shooting right and left
                                // respectively may results in some overlaping
        // computing L[i] & R[i] for each robot[i]
        for (int i = 0; i < n; i++) {
            // left range for robot i
            int md_left =
                max(w[0], v[i].first - v[i].second); // maximum left range
            int md_right = min(v[i].first + v[i].second,
                               w[w.size() - 1]); // maximum right range
            if (i > 0)
                md_left = max(md_left, v[i - 1].first + 1);
            if (i < n - 1)
                md_right = min(md_right, v[i + 1].first - 1);

            int left_start = lower_bound_custom(w, md_left);
            int left_end = upper_bound_custom(w, v[i].first);

            int right_start = lower_bound_custom(w, v[i].first);
            int right_end = upper_bound_custom(w, md_right);

            int left_walls = left_end - left_start; // no. of elements b/w range
            int right_walls =
                right_end - right_start; // no. of elements b/w range

            L[i] = left_walls;
            R[i] = right_walls;

            if (i >= 1) {
                int prev_end =
                    min(v[i - 1].first + v[i - 1].second, v[i].first - 1);
                int curr_start = md_left;

                if (prev_end >= curr_start) {
                    int left_idx = lower_bound_custom(w, curr_start);
                    int right_idx = upper_bound_custom(w, prev_end);
                    Overlap[i] = right_idx - left_idx;
                }
            }
        }
        vector<vector<int>> dp(
            n, vector<int>(2)); // dp[i][0] = robot shooting left , dp[i][1] =
                                // robot shooting right
        dp[0][0] = L[0];
        dp[0][1] = R[0]; // first robot has no issues from it's neighbours

        for (int i = 1; i < n; i++) {
            // previous robot shooted left ? , no issue with this one shooting
            // either direction previous robot shooted right ? , this have some
            // overlaps with shooting left hence , this robot shooting left may
            // have some overlaps
            dp[i][0] =
                L[i] +
                max(dp[i - 1][0],
                    dp[i - 1][1] -
                        Overlap[i]); // removing overlaps when prev shoots right
            dp[i][1] = R[i] + max(dp[i - 1][0], dp[i - 1][1]);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};