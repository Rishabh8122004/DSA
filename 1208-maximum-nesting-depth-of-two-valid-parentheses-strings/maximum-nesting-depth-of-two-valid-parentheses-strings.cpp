class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        vector<int>v(s.size());
        int noo = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(')noo++;
            else noo--;
            v[i] = noo;
        }
        stack<int>st;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(')st.push(i);
            else{
                if((v[i]%2) == 0){
                    v[i] = 0;
                    v[st.top()] = 0;
                    st.pop();
                }
                else{
                    v[i] = 1;
                    v[st.top()] = 1;
                    st.pop();
                }
            }
        }
        return v;
    }
};