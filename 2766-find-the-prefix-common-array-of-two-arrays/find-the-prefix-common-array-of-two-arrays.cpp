class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int i = 0;
        unordered_set<int> st, f;
        int n = a.size();
        while (i < n) {
            if (st.find(a[i]) != st.end()) {
                st.erase(a[i]);
            } else
                st.insert(a[i]);
            if (st.find(b[i]) != st.end()) {
                st.erase(b[i]);
            } else
                st.insert(b[i]);
            f.insert(a[i]);
            f.insert(b[i]);
            a[i] = f.size() - st.size();
            i++;
        }
        return a;
    }
};