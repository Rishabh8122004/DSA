class Solution {
public:
    string simplifyPath(string p) {
        int n = p.size();
        int i = 0;
        string s = "";
        stack<string>st;
        while(i<n){
            if(p[i] == '/'){s = "";i++;}
            while(i<n && p[i]!= '/'){s+=p[i];i++;}
            if(s == ".")continue;
            if(s == ".." && !st.empty())st.pop();
            else if(p[i] == '/' && s != "" && s != "..")st.push(s);
        }
        if(s != "" && s != ".." && s != ".")st.push(s);
        p = "";
        while(!st.empty()){
            p = st.top() + p;
            p = '/' + p;
            st.pop();
        }
        if(p == "") p = '/';
        return p;
    }
};