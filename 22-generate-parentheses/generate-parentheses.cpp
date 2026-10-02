class Solution {
public:
    vector<string>st;
    void solve(int n,int c,int o,string s){
        if(s.size() == 2*n){
            st.push_back(s);
            return;
        }
        if(o<n){
            solve(n,c,o+1,s+"(");
        }
        if(c<o){
            solve(n,c+1,o,s+")");
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        solve(n,0,0,"");
        return st;
    }
};