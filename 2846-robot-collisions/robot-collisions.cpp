class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& a, string d) {
        int n = p.size();
        for(int i = 0;i<n;i++){
            if(d[i] == 'L')a[i] = -1*a[i];
        }
        vector<vector<int>>v(n,vector<int>(2));
        for(int i = 0;i<n;i++){
            v[i][0] = p[i];
            v[i][1] = a[i];
        }
        sort(v.begin(),v.end());
        stack<int> st;
        st.push(0);
        int j = 1, x, y, i;
        while (j < n) {
            while(j<n && v[j][1]>0){st.push(j);j++;}
            if(j == n)break;
            i = st.top();
            x = v[i][1];
            y = v[j][1];
            while (j < n && !st.empty() && (x > 0 && y < 0)) {
                if (x == abs(y)) {
                    st.pop();
                    j++;
                } else if (x < abs(y)) {
                    st.pop();
                    v[j][1] += v[j][1]<0?1:-1;
                } else if (x > abs(y)) {
                    j++;
                    v[i][1] += v[i][1]<0?1:-1;
                }
                if(st.empty() || j == n)break;
                i = st.top();
                x = v[i][1];
                y = v[j][1];
            }
            if(j == n)break;
            st.push(j);
            j++;
        }
        map<int,int>mp;
        while(st.size()){
            mp[v[st.top()][0]] = v[st.top()][1];
            st.pop();
        }
        vector<int>ans;
        for(int i = 0;i<n;i++){
            if(mp.find(p[i])!=mp.end()){
                ans.push_back(abs(mp[p[i]]));
            }
        }
        return ans;
    }
};