class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int es) {
        int n = c.size();
        typedef vector<double> pr;
        priority_queue<pr> pq; 
        double ans = 0;

        for (int i = 0; i < n; i++) {
            double ratio = (double)c[i][0] / c[i][1];
            double gain = ((double)(c[i][0] + 1) / (c[i][1] + 1)) - ratio;
            pq.push({gain, ratio, (double)c[i][0], (double)c[i][1]});
            ans += ratio;
        }

        while (es--) {
            auto p = pq.top(); pq.pop();
            ans -= p[1];

            p[2] += 1;
            p[3] += 1;

            double newRatio = p[2] / p[3];
            double newGain = ((p[2] + 1) / (p[3] + 1)) - newRatio;

            ans += newRatio;
            pq.push({newGain, newRatio, p[2], p[3]});
        }

        return ans / n;
    }
};
