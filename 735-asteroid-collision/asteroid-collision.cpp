class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        vector<bool> f(n, true);
        stack<int> st;
        st.push(0);
        int j = 1, x, y, i;
        while (j < n) {
            while(j<n && a[j]>0){st.push(j);j++;}
            if(j == n)break;
            i = st.top();
            x = a[i];
            y = a[j];
            while (j < n && !st.empty() && (x > 0 && y < 0)) {
                if (x == abs(y)) {
                    st.pop();
                    j++;
                } else if (x < abs(y)) {
                    st.pop();
                } else if (x > abs(y)) {
                    j++;
                }
                if(st.empty() || j == n)break;
                i = st.top();
                x = a[i];
                y = a[j];
            }
            if(j == n)break;
            st.push(j);
            j++;
        }
        vector<int> ans(st.size());
        i = st.size() - 1;
        while (!st.empty()) {
            ans[i] = a[st.top()];
            st.pop();
            i--;
        }
        return ans;
    }
};