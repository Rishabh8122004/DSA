class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(')st.push(s[i]);
            else{
                if(st.empty())return false;
                if(s[i] == ')' ){
                    if(st.top() != '(')return false;
                    else st.pop();
                }       
            }
        }
        return st.size() == 0;
    }
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n == 0)return 0;
        int a = 0;
        int ans = 0;
        stack<int>st;
        st.push(-1);
        for(int i = 0;i<n;i++){
            if(s[i] == '(')st.push(i);
            else{
                st.pop();
            }
            if(st.empty())st.push(i);
            ans = max(ans,i-st.top());
        }
        return ans;
    }
};