class Solution {
public:
    // cost[i] = min operations to make window nums[i..i+k-1] all equal.
    // Idea: the best target is the median, so cost = sum of |a - median|.
    // Sliding median with two multisets: left = smaller half, right = larger half.
    vector<long long> cost_of_eachsubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans;
        multiset<long long> left, right;
        long long left_sum = 0, right_sum = 0, m;

        // ---- Build the first window ----
        for (int i = 0; i < k; i++) {
            // Keep sizes balanced: left gets the extra element when odd
            if (left.size() <= right.size()) {
                left.insert(nums[i]);
                left_sum += nums[i];
            } else {
                right.insert(nums[i]);
                right_sum += nums[i];
            }
            // Fix order: max of left must be <= min of right, else swap them
            // (right.empty() guard avoids dereferencing end() when k = 1)
            while (!right.empty() && (*left.rbegin() > *right.begin())) {
                int x = *left.rbegin(), y = *right.begin();
                left.erase(left.find(x));
                right.erase(right.find(y));
                right.insert(x);
                left.insert(y);
                // keep sums in sync with the swap
                left_sum -= x;
                right_sum -= y;
                left_sum += y;
                right_sum += x;
            }
        }
        // Median = top of left. Cost = (distance of left elements below m)
        //                            + (distance of right elements above m)
        m = *left.rbegin();
        ans.push_back((m * left.size() - left_sum) +
                      (right_sum - (m * right.size())));

        // ---- Slide the window: remove nums[i], add nums[j] ----
        int i = 0, j = k;
        while (j < n) {
            // Remove outgoing element from whichever half holds it
            if (!right.empty() && nums[i] > *left.rbegin()) {
                right.erase(right.find(nums[i]));
                right_sum -= nums[i];
            } else {
                left.erase(left.find(nums[i]));
                left_sum -= nums[i];
            }

            // Insert incoming element into the smaller half
            if (left.size() <= right.size()) {
                left.insert(nums[j]);
                left_sum += nums[j];
            } else {
                right.insert(nums[j]);
                right_sum += nums[j];
            }
            // Rebalance order with a swap if needed
            while (!right.empty() && (*left.rbegin() > *right.begin())) {
                int x = *left.rbegin(), y = *right.begin();
                left.erase(left.find(x));
                right.erase(right.find(y));
                right.insert(x);
                left.insert(y);
                left_sum -= x;
                right_sum -= y;
                left_sum += y;
                right_sum += x;
            }
            j++;
            i++;
            // Record cost of the new window
            m = *left.rbegin();
            ans.push_back((m * left.size() - left_sum) +
                          (right_sum - (m * right.size())));
        }
        return ans;
    }

    // dp[i][k] = min cost to pick k non-overlapping windows from starts i..end
    long long dp[100005][16];
    long long INF = 1e18;  // marks impossible states

    long long get_min_cost(int i, vector<long long>& costs, int x, int k) {
        if (k == 0)
            return 0;                    // nothing left to pick
        if (i >= (int)costs.size())
            return INF;                  // no room left, impossible
        if (dp[i][k] != -1)
            return dp[i][k];             // memoized

        // Option 1: skip the window starting at i
        long long skip = get_min_cost(i + 1, costs, x, k);
        // Option 2: take it, then jump x ahead so the next one can't overlap
        long long pick = costs[i] + get_min_cost(i + x, costs, x, k - 1);
        return dp[i][k] = min(skip, pick);
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        memset(dp, -1, sizeof(dp));                          // mark all as uncomputed
        vector<long long> costs = cost_of_eachsubarray(nums, x);  // step 1: window costs
        return get_min_cost(0, costs, x, k);                 // step 2: choose k windows
    }
};