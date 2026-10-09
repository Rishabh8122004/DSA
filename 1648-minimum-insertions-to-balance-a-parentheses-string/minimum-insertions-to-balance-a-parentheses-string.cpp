class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        stack<int>st;
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(')st.push(i);
            else{
                if((i+1<n) && (s[i+1] == ')')){
                    if(!st.empty())st.pop();
                    else{
                        ans+=1;
                    }
                    i++;
                }else{
                    ans+=1;
                    if(!st.empty())st.pop();
                    else ans+=1;
                }
            }
        }
        return ans + (st.size()*2);
    }
};