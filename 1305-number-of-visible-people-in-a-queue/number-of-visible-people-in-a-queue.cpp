class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        int n = h.size();
        vector<int>nge(n);
        stack<int>st;
        st.push(-1);
        nge[n-1] = 0;
        for(int i = n-2;i>=0;i--){
            int c = 0;
            st.push(i+1);
            while(st.size()>1 && h[i]>h[st.top()]){st.pop();c++;}
            nge[i] = c;
            if(st.size()>1)nge[i]++;
        }
        return nge;
    }
};