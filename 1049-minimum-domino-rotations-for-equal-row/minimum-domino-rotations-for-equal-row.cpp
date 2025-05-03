class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        vector<vector<int>> v(7, vector<int>(2));

        // Count frequency of each number in both t and b
        for(int i = 0; i < t.size(); i++) {
            v[t[i]][0]++;
            v[b[i]][1]++;
        }

        bool f = false, flag = false; // f: change in t or b; flag: whether change is needed
        int m1 = 0, n1, n2, m2 = 0;

        // Find the number with max frequency in t and b
        for(int i = 0; i < v.size(); i++) {
            if(m1 < v[i][0]) {
                m1 = v[i][0];
                n2 = i; // candidate from t
            }
            if(m2 < v[i][1]) {
                m2 = v[i][1];
                n1 = i; // candidate from b
            }
        }

        // Decide which row to try converting
        f = (m1 > m2) ? false : true;

        int ans = -1;

        if(f) {
            // Try to convert b to match n1
            for(int i = 0; i < b.size(); i++) {
                if(b[i] != n1 && t[i] == n1) {
                    flag = true;
                    swap(b[i], t[i]);
                    ans += (ans == -1) ? 2 : 1;
                }
                if(b[i] != n1 && t[i] != n1) {
                    f = false;
                    ans = -1;
                    break;
                }
            }
        }

        if(!f) {
            flag = false;
            // Try to convert t to match n2
            for(int i = 0; i < t.size(); i++) {
                if(t[i] != n2 && b[i] == n2) {
                    flag = true;
                    swap(b[i], t[i]);
                    ans += (ans == -1) ? 2 : 1;
                }
                if(t[i] != n2 && b[i] != n2) {
                    return -1;
                }
            }
        }

        if(!flag && ans == -1) return 0;
        return ans;
    }
};
