class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int>nse(n,-1),pse(n,-1);
        stack<int>st;
        for(int i = 1;i<n;i++){
            st.push(i-1);
            while(!st.empty() && (h[st.top()]>=h[i]))st.pop();
            if(!st.empty())pse[i] = st.top();
        }
        while(!st.empty())st.pop();
        for(int i = n-2;i>-1;i--){
            st.push(i+1);
            while(!st.empty() && (h[st.top()]>=h[i]))st.pop();
            if(!st.empty())nse[i] = st.top();
        }
        int ans = 0,x;
        for(int i = 0;i<n;i++){
            cout<<pse[i]<<"  "<<nse[i]<<endl;
            x = 0;
            x+=(pse[i] == -1?(h[i]*(i+1)):(h[i]*(i-pse[i])));
            x+=(nse[i] == -1?(h[i]*(n-i)):(h[i]*(nse[i]-i)));
            x-=h[i];
            ans = max(ans,x);
        }
        return ans;
    }
};