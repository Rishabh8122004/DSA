class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        int n = h.size();
        vector<int>ans(n,0);
        stack<int>st;
        st.push(-1);
        for(int i = n-2;i>=0;i--){
            int c = 0;// number of pops performed for this number is the number of people it can see
            st.push(i+1);
            while(st.size()>1 && h[i]>h[st.top()]){st.pop();c++;}
            ans[i] = c;
            if(st.size()>1)ans[i]++; // if any number is greater than it,it is also be seen 
        }
        return ans;
    }
};