class Solution {
public:
    int n ;vector<int> v;
    struct node {
        long long score = -1;
        vector<int> idx;
    };
     vector<vector<node>> dp;
    node solve(vector<vector<int>>& in, int i, int k) {
        if (k == 0 || i >= n) {
            return dp[i][k] = node();
        }
        if(dp[i][k].score != -1)return dp[i][k];
        node skip = solve(in, i + 1, k);    // skip this interval
        node temp = solve(in, v[i], k - 1); // take this interval
        node take;
        take.score = in[i][2] + temp.score; // score of this interval + further chosen intervals
        take.idx = temp.idx;
        take.idx.push_back(in[i][3]);
        sort(take.idx.begin(), take.idx.end());
        node result;
        if (take.score > skip.score) {
            result = take;
        } else if (take.score == skip.score) {
            result = (take.idx < skip.idx)?take:skip;
        }
        else{
            result = skip;
        }
        return dp[i][k] = result;
    }
    vector<int> maximumWeight(vector<vector<int>>& in) {
        n = in.size();
        for (int i = 0; i < n; i++) {
            in[i].push_back(i);
        }
        sort(in.begin(), in.end());
        // storing next non - overlapping interval index using binary search;
        v.resize(n);
        for (int i = 0; i < n; i++) {
            int lo = 0, hi = n - 1;
            int next_idx = n;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (in[mid][0] > in[i][1]) {
                    next_idx = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            v[i] = next_idx;
        }
        dp.resize(n+1, vector<node>(5));
        return solve(in, 0, 4).idx;
    }
};