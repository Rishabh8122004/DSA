class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        int qn = queries.size();

        vector<pair<int,int>> events;   // (time, server)
        for (int i = 0; i < m; i++) {
            events.push_back({logs[i][1], logs[i][0]});
        }
        sort(events.begin(), events.end());

        vector<pair<int,int>> qs;       // (query time, original index)
        for (int i = 0; i < qn; i++) {
            qs.push_back({queries[i], i});
        }
        sort(qs.begin(), qs.end());

        vector<int> cnt(n + 1, 0);
        int active = 0;    // servers with at least one request in the window
        int left = 0;      // first log still inside the window
        int right = 0;     // first log not yet added
        vector<int> ans(qn);

        for (int k = 0; k < qn; k++) {
            int hi = qs[k].first;
            int lo = hi - x;

            while (right < m && events[right].first <= hi) {
                int s = events[right].second;
                if (cnt[s] == 0) active++;
                cnt[s]++;
                right++;
            }
            while (left < right && events[left].first < lo) {
                int s = events[left].second;
                cnt[s]--;
                if (cnt[s] == 0) active--;
                left++;
            }
            ans[qs[k].second] = n - active;
        }
        return ans;
    }
};