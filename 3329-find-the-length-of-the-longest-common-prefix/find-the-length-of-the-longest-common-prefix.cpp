class Solution {
public:
    int get_length(int x) {
        int y = 0;
        while (x) {
            y++;
            x /= 10;
        }
        return max(1, y);
    }
    int longestCommonPrefix(vector<int>& a1, vector<int>& a2) {
        int n = a2.size();
        unordered_set<int> st;
        for (int i = n - 1; i >= 0; i--) {
            int x = a2[i];
            if (x == 0)
                st.insert(x);
            while (x) {
                st.insert(x);
                x /= 10;
            }
        }
        int ans = 0;

        for (int i = 0; i < a1.size(); i++) {
            int x = a1[i];
            if (x == 0) {
                if (st.find(x) != st.end())
                    ans = max(ans, get_length(x));
            }
            while (x) {
                if (st.find(x) != st.end())
                    ans = max(ans, get_length(x));
                x /= 10;
            }
        }
        return ans;
    }
};