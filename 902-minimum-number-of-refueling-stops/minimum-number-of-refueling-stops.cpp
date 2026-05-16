class Solution {
public:
    int minRefuelStops(int t, int f, vector<vector<int>>& st) {
        st.push_back({t, 0});
        priority_queue<int> pq;
        int stops = 0;
        int i = 0;
        while (i < st.size()) {
            if (f >= st[i][0]) { // can reach this station .. hence put this fuel in pq for further use
                pq.push(st[i][1]);
                i++;
            }
            else { // can't reach this station.. use the largest fuel if any ..
                if (pq.empty()) return -1; // no remaining fuel .. can't move further.. return -1
                f += pq.top();
                pq.pop();
                stops++; // refueled somewhere.. hence stops++
            }
        }
        return stops;
    }
};