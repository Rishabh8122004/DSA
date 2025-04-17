class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        stack<int>st;
        st.push(-1);
        st.push(n2[n2.size()-1]);
        vector<vector<int>>v(n2.size());
        v.back() = {n2[n2.size()-1],-1};
        for(int i = n2.size()-2;i>=0;i--){
            while(st.size()>1&&st.top()<=n2[i])st.pop();
            v[i] = {n2[i],st.top()};
            st.push(n2[i]);
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(int i = 0;i<n1.size();i++){
            int lo = 0,hi = v.size()-1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(v[mid][0] == n1[i]){ans.push_back(v[mid][1]);break;}
                else if(v[mid][0]<n1[i]){lo++;}
                else hi--;
            }
        }
        return ans;
    }
};