class Solution {
public:
    int maxEvents(vector<vector<int>>& e) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            start, end;
        map<int, int> idx;
        int m = 0;
        for (int i = 0; i < e.size(); i++) {
            m = max(m, e[i][1]);
            start.push({e[i][0], i});
            end.push({e[i][1], i});
            idx.insert({i, 1});
        }
        int d = start.top().first, ans = 0;
        while (!end.empty() && d <= m && !start.empty()) {
            while (!end.empty() && !idx.count(end.top().second)) end.pop();
            while (!end.empty() && d > end.top().first) {
                idx.erase(end.top().second);
                end.pop();
            }
            while (!start.empty() && !idx.count(start.top().second)) start.pop();
            if (!end.empty() && idx.count(end.top().second) && (d <= end.top().first && d >= e[end.top().second][0])) {
                ans++;
                idx.erase(end.top().second);
                end.pop();
                cout << end.top().second << " " << d << endl;
            } else if (!start.empty() && idx.count(start.top().second) && (d >= start.top().first && d <= e[start.top().second][1])) {
                ans++;
                idx.erase(start.top().second);
                start.pop();
                cout << start.top().second << " " << d << endl;
            }
            d++;
        }
        return ans;
    }
};