class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            q.push(s[i]);
        }
        for (int i = sandwiches.size() - 1; i >= 0; i--) {
            st.push(sandwiches[i]);
        }
        int n = q.size();
        bool flag = true;
        while (flag) {
            n = q.size();
            flag = false;
            while (!q.empty()) {
                if(n <= 0)break;
                if (q.front() == st.top()) {
                    q.pop();
                    st.pop();
                    flag = true;
                } else {
                    q.push(q.front());
                    q.pop();
                }
                n--;
            }
        }
        return q.size();
    }
};