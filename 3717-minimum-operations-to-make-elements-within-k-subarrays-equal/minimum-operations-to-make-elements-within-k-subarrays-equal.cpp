class Solution {
public:
    vector<long long> cost_of_eachsubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans;
        multiset<long long> left, right;
        long long left_sum = 0, right_sum = 0, m;
        for (int i = 0; i < k; i++) {
            if (left.size() <= right.size()) {
                left.insert(nums[i]);
                left_sum += nums[i];
            } else {
                right.insert(nums[i]);
                right_sum += nums[i];
            }
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
        }
        m = *left.rbegin();
        ans.push_back((m * left.size() - left_sum) +
                      (right_sum - (m * right.size())));
        int i = 0, j = k;
        while (j < n) {
            if (!right.empty() && nums[i] > *left.rbegin()) {
                right.erase(right.find(nums[i]));
                right_sum -= nums[i];
            } else {
                left.erase(left.find(nums[i]));
                left_sum -= nums[i];
            }

            if (left.size() <= right.size()) {
                left.insert(nums[j]);
                left_sum += nums[j];
            } else {
                right.insert(nums[j]);
                right_sum += nums[j];
            }
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
            m = *left.rbegin();
            ans.push_back((m * left.size() - left_sum) +
                          (right_sum - (m * right.size())));
        }
        return ans;
    }
    long long dp[100005][16];
    long long INF = 1e18;
    long long get_min_cost(int i, vector<long long>& costs, int x, int k) {
        if (k == 0)
            return 0;
        if (i >= (int)costs.size())
            return INF; // no room left, impossible
        if (dp[i][k] != -1)
            return dp[i][k];
        long long skip = get_min_cost(i + 1, costs, x, k);
        long long pick = costs[i] + get_min_cost(i + x, costs, x, k - 1);
        return dp[i][k] = min(skip, pick);
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        memset(dp, -1, sizeof(dp));
        vector<long long> costs = cost_of_eachsubarray(nums, x);
        return get_min_cost(0, costs, x, k);
    }
};