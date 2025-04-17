class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        stack<int>st;
        st.push(-1);
        st.push(n2[n2.size()-1]);
        vector<int>v(n2.size());
        v.back() = -1;
        for(int i = n2.size()-2;i>=0;i--){
            while(st.size()>1&&st.top()<=n2[i])st.pop();
            v[i] = st.top();
            st.push(n2[i]);
        }
        vector<int>ans;
        for(int i = 0;i<n1.size();i++){
            for(int j = 0;j<n2.size();j++){
                if(n1[i] == n2[j]){ans.push_back(v[j]);break;}
            }
        }
        return ans;
    }
};