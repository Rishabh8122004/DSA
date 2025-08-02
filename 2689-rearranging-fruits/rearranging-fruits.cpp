class Solution {
public:
    long long minCost(vector<int>& a, vector<int>& b) {
        long long ans = 0;
        unordered_map<int,int> m1, m2;
        priority_queue<int, vector<int>, greater<int>> p; // min heap
        priority_queue<int> q; // max heap
        int n = a.size();
        int mini = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            m1[a[i]]++;
            m2[b[i]]++;
            mini = min({mini, a[i], b[i]});
        }

        set<int> mp;

        for(auto p1 : m1) {
            if((p1.second + m2[p1.first]) % 2 == 1) return -1;

            int diff = p1.second - m2[p1.first];
            if(diff > 0) {
                for(int i = 0; i < diff / 2; i++) {
                    p.push(p1.first);
                }
                mp.insert(p1.first);
            }
        }

        for(auto p1 : m2) {
            if((p1.second + m1[p1.first]) % 2 == 1) return -1;

            int diff = p1.second - m1[p1.first];
            if(diff > 0 && mp.find(p1.first) == mp.end()) {
                for(int i = 0; i < diff / 2; i++) {
                    q.push(p1.first);
                }
            }
        }

        if(p.size() != q.size()) return -1;

        while(!p.empty()) {
            int x = p.top(); p.pop();
            int y = q.top(); q.pop();

            ans += min((long long)min(x, y), (long long)2 * mini);
        }

        return ans;
    }
};
