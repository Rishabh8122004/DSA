class Solution {
public:
    bool isValid(string s) {
       stack <char> st;
       st.push(s[0]);
       for(int i = 1;i<s.size();i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
        else{
            if(!st.empty()){
            if(s[i] == ')' && st.top() == '(') st.pop();
            else if( s[i] == '}' && st.top() == '{') st.pop();
            else if(s[i] == ']' && st.top()== '[') st.pop();
            else return false;
            }
            else return false;
        }
       }
       return st.empty();
    }
};