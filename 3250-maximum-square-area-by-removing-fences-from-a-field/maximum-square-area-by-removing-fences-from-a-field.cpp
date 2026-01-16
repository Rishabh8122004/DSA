class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        const int MOD = 1e9 + 7;

        // add boundaries
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        vector<int> H, V;

        // all horizontal distances
        for (int i = 0; i < h.size(); i++) {
            for (int j = i + 1; j < h.size(); j++) {
                H.push_back(h[j] - h[i]);
            }
        }

        // all vertical distances
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                V.push_back(v[j] - v[i]);
            }
        }

        sort(H.begin(), H.end());
        sort(V.begin(), V.end());

        int i = H.size() - 1;
        int j = V.size() - 1;

        while (i >= 0 && j >= 0) {
            if (H[i] == V[j]) {
                long long d = H[i];
                return (d * d) % MOD;
            } else if (H[i] > V[j]) {
                i--;
            } else {
                j--;
            }
        }

        return -1;
    }
};