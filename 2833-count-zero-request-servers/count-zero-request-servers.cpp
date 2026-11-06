class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& l, int x,
                             vector<int>& queries) {
        for (int i = 0; i < l.size(); i++) {
            swap(l[i][0], l[i][1]);
        }
        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }
        sort(l.begin(), l.end());
        sort(q.begin(), q.end());
        int k = 0;
        int i = -1, j = -1, lo, hi;
        vector<int> ans(q.size());
        unordered_map<int, int> mp;
        while (k < q.size()) {
            lo = q[k][0] - x;
            hi = q[k][0];
            while ((j + 1 < l.size()) && (l[j + 1][0] <= hi)) {
                mp[l[j + 1][1]]++;
                j++;
            }
            if (i == -1 && j >= 0)
                i = 0;
            while ((i < l.size()) && (l[i][0] < lo)) {
                if(mp[l[i][1]])mp[l[i][1]]--;
                if(mp[l[i][1]] == 0){
                    mp.erase(l[i][1]);
                }
                i++;
            }
            if ((i == -1 && j == -1) || (i > j))
                ans[q[k][1]] = n;
            else
                ans[q[k][1]] = (n - mp.size());
            k++;
        }
        return ans;
    }
};