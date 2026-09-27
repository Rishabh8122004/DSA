class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        // match[i] = index of the matching parenthesis
        vector<int> match(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();

                match[i] = j;
                match[j] = i;
            }
        }

        string ans = "";
        int i = 0;
        int direction = 1;

        while (i >= 0 && i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = match[i];
                direction = -direction;
            } else {
                ans += s[i];
            }

            i += direction;
        }

        return ans;
    }
};