class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        vector<int> f(27);
        for (int i = 0; i < s.size(); i++) {
            f[s[i] - 'a']++;
        }
        vector<bool> taken(27, false);
        for (int i = 0; i < s.size(); i++) {
            if (taken[s[i] - 'a']){f[s[i] - 'a']--; continue;}
            while (!st.empty() && s[i] < st.top() && f[st.top() - 'a'] > 0) {
                taken[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            taken[s[i] - 'a'] = true;
            f[s[i] - 'a']--;
        }
        s = "";
        while(!st.empty()){
            s = st.top()+s;
            st.pop();
        }
        return s;
    }
};